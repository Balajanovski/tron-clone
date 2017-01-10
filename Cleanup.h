//
// Created by JULIA BALAJAN on 1/01/2017.
//

#ifndef TRON_CLEANUP_H
#define TRON_CLEANUP_H

#include <memory>

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdexcept>
#include <sstream>

template <class T>
void cleanup(T *) {
    static_assert(!sizeof(T*), "No overload of `cleanup` for this type.");
}

/*
 * Recurse through the list of arguments to clean up, cleaning up
 * the first one in the list each iteration.
 */
template<typename... Args>
void cleanup(Args *... args){
    using ex = int[];
    (void)ex{(cleanup(args), 0)..., 0};
}
/*
 * These specializations serve to free the passed argument and also provide the
 * base cases for the recursive call above, eg. when args is only a single item
 * one of the specializations below will be called by
 * cleanup(std::forward<Args>(args)...), ending the recursion
 * We also make it safe to pass nullptrs to handle situations where we
 * don't want to bother finding out which values failed to load (and thus are null)
 * but rather just want to clean everything up and let cleanup sort it out
 */
inline void cleanup(SDL_Window *win){
    if (!win){
        return;
    }
    SDL_DestroyWindow(win);
}

inline void cleanup(SDL_Renderer *ren){
    if (!ren){
        return;
    }
    SDL_DestroyRenderer(ren);
}

inline void cleanup(SDL_Texture *tex){
    if (!tex){
        return;
    }
    SDL_DestroyTexture(tex);
}

inline void cleanup(SDL_Surface *surf){
    if (!surf){
        return;
    }
    SDL_FreeSurface(surf);
}

inline void cleanup(TTF_Font *font) {
    if(!font)
        return;
    
    TTF_CloseFont(font);
}

struct Cleaner {
	template <class T>
	void operator() (T *p) const {
		cleanup(p);
	}
};

using SdlWinPtr = std::unique_ptr<SDL_Window, Cleaner>;
using SdlRenPtr = std::unique_ptr<SDL_Renderer, Cleaner>;
using SdlTexPtr = std::unique_ptr<SDL_Texture, Cleaner>;
using SdlSurfPtr = std::unique_ptr<SDL_Surface, Cleaner>;
using TtfFontPtr = std::unique_ptr<TTF_Font, Cleaner>;

// Helper to avoid deleting functions all over the place
struct NoCopy {
	NoCopy() = default;
	NoCopy(NoCopy const &) = delete;
	NoCopy &operator = (NoCopy const &) = delete;
};

struct SdlHandle : NoCopy {
	SdlHandle(Uint32 flags) {
		if(SDL_Init(flags))
			throw std::runtime_error("Unable to initialize SDL");
	}
	
	~SdlHandle() { SDL_Quit(); }
};

struct ImgHandle : NoCopy {
	ImgHandle(int flags) {
		if(IMG_Init(flags) != flags)
			throw std::runtime_error("Unable to initialize SDL_img");
	}
	
	~ImgHandle() { IMG_Quit(); }
};

struct TtfHandle : NoCopy {
	TtfHandle() {
		if(TTF_Init() == -1)
			throw std::runtime_error("Unable to initialize SDL_ttf");
	}
	
	~TtfHandle() { TTF_Quit(); }
};

[[noreturn]] inline void throwSdlError(const std::string &msg) {
    std::stringstream ss;
    ss << msg << " error: " << SDL_GetError();
	throw std::runtime_error(ss.str());
}

#endif //TRON_CLEANUP_H
