#include <blah.h>

#include "actor.h"
#include "solid.h"

#include "controllable.h"
#include "floor.h"
#include "block.h"
using namespace Blah;

Batch batch;
std::vector<Actor*> actors; // TODO use smart pointers instead, avoid casting on the push_back() calls
std::vector<Solid*> solids;

void startup()
{
    actors.push_back(new Controllable(900,100,64,64));
    solids.push_back(new Floor(2000, 50));
    solids.push_back(new Block(900,400,64,128));
}

void render()
{
    App::backbuffer->clear(Color::black);

    auto scale = Vec2((float) App::width()/1280, (float) App::height()/720);
    auto transform = Mat3x2::create_transform(Vec2::zero, Vec2::zero, scale, 0);
    batch.push_matrix(transform);

    for (auto & solid:solids) {
        solid->draw(&batch);
    }

    for (auto & actor:actors) {
        actor->update(solids);
        actor->draw(&batch);
    }

    batch.pop_matrix();

    batch.render();
    batch.clear();
}

void update()
{
    if (Input::pressed(Key::Escape)) App::exit();
    if (Input::pressed(Key::C)) {
        int x = (int)Input::mouse().x;
        int y = (int)Input::mouse().y;
        auto c = new Controllable(x, y,64,64);
        if (!c->collideAt(solids, 0, 0)) actors.push_back(c); // TODO check before creation
        else delete c;
    }
    // Entity deleting
    for (auto it = solids.begin(); it != solids.end();) {
        if ((*it)->deleting()) {
            auto s = *it;
            it = solids.erase(it);
            delete s;
        }
        else it++;
    }
    for (auto it = actors.begin(); it != actors.end();) {
        if ((*it)->deleting()) {
            auto s = *it;
            it = actors.erase(it);
            delete s;
        }
        else it++;
    }
}

void shutdown()
{
    for (auto & actor:actors) {
        delete actor;
    }

    for (auto & solid:solids) {
        delete solid;
    }
}

int main()
{
    Config config;
    config.name = "Physics thingy";
    config.width = 1280;
    config.height = 720;
    config.target_framerate = 60;
    config.on_startup = startup;
    config.on_render = render;
    config.on_update = update;
    config.on_shutdown = shutdown;

    App::run(&config);
    return 0;
}