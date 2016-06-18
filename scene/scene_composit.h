#ifndef SCENE_COMPOSIT_H
#define SCENE_COMPOSIT_H
#include "composit_object/composit_object.h"

class scene_composit
{
public:
    friend class keeper;
    scene_composit(){}
    void add(base_object* obj);


    friend class model_conver_manager;
    friend class camera_conver_manager;
private:
    composit_object objects;
};

#endif // SCENE_COMPOSIT_H
