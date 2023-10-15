#pragma once

class Application {

public:
  virtual void Init() = 0;
  virtual void MainLoop() = 0;
  virtual void Terminate() = 0;
  void Run() {
    MainLoop();
    Terminate();
  }
};