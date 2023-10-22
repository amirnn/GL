#pragma once

class Application
{
  public:
  virtual ~Application() = default;
  virtual void Init() = 0;
  virtual void MainLoop() = 0;
  virtual void Terminate() = 0;
  void Run()
  {
    MainLoop();
  }
};