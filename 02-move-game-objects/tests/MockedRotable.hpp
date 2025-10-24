#pragma once
#include "IRotable.hpp"

namespace mock {

class MockedGetDirectionError : public IRotable {
public:
  int GetDirection() const override { throw std::runtime_error("GetDirectionException"); } 
  int GetAngularVelocity() const override { return 0; } 
  int GetDirectionsNumber() const override { return 1; } 
  void SetDirection(int ) override {}  
};

class MockedGetAngularVelocityError : public IRotable {
  public: 
    int GetDirection() const override { return 0; }  

    int GetAngularVelocity() const override { 
      throw std::runtime_error("GetAngularVelocityException"); 
    }  
    int GetDirectionsNumber() const override { return 1; }  

    void SetDirection(int ) override {} 
};

class MockedGetDirectionsNumberError : public IRotable {
public: 
    int GetDirection() const override { return 0; }  
    
    int GetAngularVelocity() const override { return 1; }  
    
    int GetDirectionsNumber() const override { 
        throw std::runtime_error("GetDirectionsNumberException"); 
    }  
    void SetDirection(int ) override {} 
};

class MockedSetDirectionError : public IRotable {
public: 
    int GetDirection() const override { return 0; }  
    
    int GetAngularVelocity() const override { return 0; }  
    
    int GetDirectionsNumber() const override { return 1; }  
    
    void SetDirection(int ) override {
      throw std::runtime_error("SetDirectionException"); 
    } 
};
}