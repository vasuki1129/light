#include "../doctest/doctest.h"
#include "../engine/transform.h"
#include "../engine/component.h"
using namespace engine;

TEST_CASE("4.1.TC1") {
  Transform* test_transform = new Transform();
  Transform* child_transform = new Transform();
  //redirect cout to a string so we can check for the error message
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  test_transform->AddChild(child_transform);
  std::cout.rdbuf(old_cout);
  CHECK(buffer.str() == ""); //no output expected
}
TEST_CASE("4.1.TC2") {
  Transform* test_transform = new Transform();
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  test_transform->AddChild(nullptr);
  std::cout.rdbuf(old_cout);
  CHECK(buffer.str() != ""); //some kind of log output expected    
}

TEST_CASE("4.2.TC1") {
  Transform* test_transform = new Transform();
  Component* test_component = new Component();
  //redirect cout to a string so we can check for the error message
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  test_transform->AddComponent(test_component);
  std::cout.rdbuf(old_cout);
  CHECK(buffer.str() == ""); //no output expected
}
TEST_CASE("4.2.TC3") {
  Transform* test_transform = new Transform();
  Component* test_component = nullptr;
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  test_transform->AddComponent(test_component);
  std::cout.rdbuf(old_cout);
  CHECK(buffer.str() != ""); //some kind of log output expected
}

TEST_CASE("4.3.TC1") {
  Transform* test_transform = new Transform();
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  Transform* out = test_transform->FindChildByName("string");
  std::cout.rdbuf(old_cout);
  CHECK(out == nullptr);
  delete test_transform;
}
TEST_CASE("4.3.TC2") {
  Transform* test_transform = new Transform();
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  Transform* out = test_transform->FindChildByName("");
  std::cout.rdbuf(old_cout);
  CHECK(out == nullptr);
  delete test_transform;
}

TEST_CASE("4.4.TC1") {
  Transform* test_transform = new Transform();
  Component* out = test_transform->FindComponentByUID(1);
  CHECK(out == nullptr);
  delete test_transform;
}
TEST_CASE("4.4.TC7") {
  Transform* test_transform = new Transform();
  Transform* out = test_transform->FindTransformByUID(UINT64_MAX-1);
  CHECK(out == nullptr);
  delete test_transform;
}
TEST_CASE("4.4.TC2") {
  Transform* test_transform = new Transform();
  Component* out = test_transform->FindComponentByUID(0);
  CHECK(out == nullptr);
  delete test_transform;
}
TEST_CASE("4.4.TC7") {
  Transform* test_transform = new Transform();
  Component* out = test_transform->FindComponentByUID(UINT64_MAX-1);
  CHECK(out == nullptr);
  delete test_transform;
}
TEST_CASE("4.4.TC8") {
  Transform* test_transform = new Transform();
  Component* out = test_transform->FindComponentByUID(UINT64_MAX);
  CHECK(out == nullptr);
  delete test_transform;
}
TEST_CASE("4.4.TC9") {
  Transform* test_transform = new Transform();
  Component* out = test_transform->FindComponentByUID(UINT64_MAX+1);
  CHECK(out == nullptr);
  delete test_transform;
}

TEST_CASE("4.5.TC1") {
  Transform* test_transform = new Transform();
  Transform* out = test_transform->FindTransformByUID(1);
  CHECK(out == nullptr);
  delete test_transform;
}
TEST_CASE("4.5.TC2") {
  Transform* test_transform = new Transform();
  Transform* out = test_transform->FindTransformByUID(0);
  CHECK(out == nullptr);
  delete test_transform;
}
TEST_CASE("4.5.TC7") {
  Transform* test_transform = new Transform();
  Transform* out = test_transform->FindTransformByUID(UINT64_MAX-1);
  CHECK(out == nullptr);
  delete test_transform;
}
TEST_CASE("4.5.TC8") {
  Transform* test_transform = new Transform();
  Transform* out = test_transform->FindTransformByUID(UINT64_MAX);
  CHECK(out == nullptr);
  delete test_transform;
}
TEST_CASE("4.5.TC9") {
  Transform* test_transform = new Transform();
  Transform* out = test_transform->FindTransformByUID(UINT64_MAX+1);
  CHECK(out == nullptr);
  delete test_transform;
}

TEST_CASE("4.6.TC1") {
  Transform* test_transform = new Transform();
  Component* out = test_transform->GetComponent("string");
  CHECK(out == nullptr);
  delete test_transform;
}
TEST_CASE("4.6.TC2") {
  Transform* test_transform = new Transform();
  Component* out = test_transform->GetComponent("");
  CHECK(out == nullptr);
  delete test_transform;
}

TEST_CASE("4.10.TC1") {
  Transform* test_transform = new Transform();
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  test_transform->Rotate(glm::vec3(1.0,0.0,0.0), 90.0f);
  std::cout.rdbuf(old_cout);
  CHECK(buffer.str() == ""); //no output expected
  delete test_transform;
}
TEST_CASE("4.10.TC2") {
  Transform* test_transform = new Transform();
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  test_transform->Rotate(glm::vec3(1.0,0.0,0.0), 90);
  std::cout.rdbuf(old_cout);
  CHECK(buffer.str() == ""); //no output expected
  delete test_transform;
}
TEST_CASE("4.10.TC3") {
  Transform* test_transform = new Transform();
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  test_transform->Rotate(glm::vec3(0.0,0.0,0.0), 90.0f);
  std::cout.rdbuf(old_cout);
  CHECK(buffer.str() != ""); //Error log output expected
  delete test_transform;
}

TEST_CASE("4.11.TC1") {
  Transform* test_transform = new Transform();
  glm::vec3 test_vector = glm::vec3(2.0,3.0,2.0);
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  test_transform->Scale(test_vector);
  std::cout.rdbuf(old_cout);
  CHECK(buffer.str() == ""); //no output expected
  delete test_transform;
}
TEST_CASE("4.11.TC2") {
  Transform* test_transform = new Transform();
  glm::vec3 test_vector = glm::vec3(1.0,1.0,1.0);
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  test_transform->Scale(test_vector);
  std::cout.rdbuf(old_cout);
  CHECK(buffer.str() == ""); //no output expected
  delete test_transform;
}
TEST_CASE("4.11.TC3") {
  Transform* test_transform = new Transform();
  glm::vec3 test_vector = glm::vec3(0.0,0.0,0.0);
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  test_transform->Scale(test_vector);
  std::cout.rdbuf(old_cout);
  CHECK(buffer.str() == ""); //no output expected
  delete test_transform;
}

TEST_CASE("4.12.TC1") {
  Transform* test_transform = new Transform();
  glm::vec3 test_vector = glm::vec3(2.0,3.0,2.0);
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  test_transform->Translate(test_vector);
  std::cout.rdbuf(old_cout);
  CHECK(buffer.str() == ""); //some kind of log output expected 
  delete test_transform;
}
TEST_CASE("4.12.TC2") {
  Transform* test_transform = new Transform();
  glm::vec3 test_vector = glm::vec3(0.0,0.0,0.0);
  std::stringstream buffer;
  std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
  test_transform->Translate(test_vector);
  std::cout.rdbuf(old_cout);
  CHECK(buffer.str() == ""); //some kind of log output expected 
  delete test_transform;
}
