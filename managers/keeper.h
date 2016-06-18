#ifndef KEEPER
#define KEEPER
#include "base_manager/base_manager.h"
#include "keeper_error.h"
#include "scene/scene_composit.h"
#include "model/base_model.h"
#include "camera/base_camera.h"
#include <cstddef>
class keeper : public base_manager
{
private:
    scene_composit* sc;
public:
    keeper() : sc(NULL){}
    ~keeper()
    {
        delete sc;
    }

    void set_scene(scene_composit* scene)
    {
        this->sc = scene;
    }

    void delete_model(size_t index)
    {
        if(!sc)
            throw keeper_error::no_scene_error();
        size_t id_obj = 0;
        for(iterator<base_object*> it = this->sc->objects.begin(); index && it!=this->sc->objects.end(); it++)
        {
            id_obj++;
            if((*it)->is_display())
                index--;
        }
        if(!index)
            this->sc->objects.del(id_obj);
        else
            throw keeper_error::delete_model_error();

    }

    void delete_camera(size_t index)
    {
        if(!sc)
            throw keeper_error::no_scene_error();
        size_t id_obj = 0;
        for(iterator<base_object*> it = this->sc->objects.begin(); index && it!=this->sc->objects.end(); it++)
        {
            id_obj++;
            if(!(*it)->is_display())
                index--;
        }
        if(!index)
            this->sc->objects.del(id_obj);
        else
            throw keeper_error::delete_camera_error();
    }

    base_model* get_model(size_t index)
    {
        if(!sc)
            throw keeper_error::no_scene_error();
        ssize_t id_obj = -1;
        index++;
        for(iterator<base_object*> it = this->sc->objects.begin(); index && it<=this->sc->objects.end(); it++)
        {
            id_obj++;
            if((*it)->is_display())
                index--;
        }
        if(!index)
            return  (base_model*)this->sc->objects[id_obj];
        else
        {
            throw keeper_error::model_error();
            return NULL;
        }
    }

    base_camera* get_camera(size_t index)
    {
        if(!sc)
            throw keeper_error::no_scene_error();
        ssize_t id_obj = -1;
        index++;
        for(iterator<base_object*> it = this->sc->objects.begin(); index && it<=this->sc->objects.end(); it++)
        {
            id_obj++;
            if(!(*it)->is_display())
                index--;
        }
        if(!index)
            return  (base_camera*)this->sc->objects[id_obj];
        else
        {
            throw keeper_error::camera_error();
            return NULL;
        }
    }

    friend class model_conver_manager;
    friend class camera_conver_manager;

    composit_object::it objects_begin()
    {
        if(!sc)
            throw keeper_error::no_scene_error();
        return this->sc->objects.begin();
    }

    composit_object::it objects_end()
    {
        if(!sc)
            throw keeper_error::no_scene_error();
        return this->sc->objects.end();
    }
};

#endif // KEEPER

