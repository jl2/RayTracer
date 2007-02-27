#ifndef RAY_TRACE_TEXTURE_H
#define RAY_TRACE_TEXTURE_H

#include "globaldefs.h"
#include "color.h"

class Texture {
public:
    Texture(Color kd=Color(0.0,0.0,0.0,0.0),
	    Color ka=Color(0.0,0.0,0.0,0.0),
	    Color ks=Color(0.0,0.0,0.0,0.0),
	    real n=12.0,
	    Color kr=Color(0.0,0.0,0.0,0.0),
	    Color kt=Color(0.0,0.0,0.0,0.0),
	    real ior=1.0);
    Color &kd();
    Color &ka();
    Color &ks();
    Color &kt();
    Color &kr();
    real &n();
    real &ior();
private:
    Color kdiffuse;
    Color kambient;
    Color kspecular;
    real specn;
    Color kreflect;
    Color ktrans;
    real indexOfRefraction;
};

#endif
