#ifndef ENTRYPOINT_H_INCLUDED
#define ENTRYPOINT_H_INCLUDED


extern bez::Application *bez::CreateApplication();

int main(int argc, char **argv) {
  bez::Application *App = bez::CreateApplication();
  App->run();
  delete App;
  return 0;
}

#endif // ENTRYPOINT_H_INCLUDED
