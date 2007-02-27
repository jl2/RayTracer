#include "texture.h"

Texture::Texture(Color kd, Color ka,
		 Color ks, real n,
		 Color kr,
		 Color kt, real ior)
  : kdiffuse(kd),
    kambient(ka),
    kspecular(ks),
    specn(n),
    kreflect(kr),
    ktrans(kt),
    indexOfRefraction(ior) {}

Color &Texture::kd() {
  return kdiffuse;
}
Color &Texture::ka() {
  return kambient;
}
Color &Texture::ks() {
  return kspecular;
}
Color &Texture::kr() {
  return kreflect;
}
Color &Texture::kt() {
  return ktrans;
}
real &Texture::n() {
  return specn;
}
real &Texture::ior() {
  return indexOfRefraction;
}
