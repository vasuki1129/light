#pragma once
#include <glm/glm.hpp>
#include "camera_component.h"

namespace engine
{
  class CollisionComponent;
  class TriggerComponent;

struct Ray
{
  glm::vec3 position;
  glm::vec3 direction;
};


/**
 * Tests whether a given ray intersects with a given transformed bounding box
 *
 * @param ray_origin Ray origin, in world space
 * @param ray_direction Ray direction (NOT target position!), in world space. Must be normalize()'d
 * @param aabb_min Minimum X,Y,Z coords of the mesh when not transformed at all.
 * @param aabb_max Maximum X,Y,Z coords. Often aabb_min*-1 if your mesh is centered, but it's not always the case.
 * @param ModelMatrix Transformation applied to the mesh.
 * @returns Whether the ray intersects the given bounding box with the given transformation.
 */
bool TestRayOBBIntersection(
    glm::vec3 ray_origin,        
    glm::vec3 ray_direction,                                      
    glm::vec3 aabb_min,                                           
    glm::vec3 aabb_max,                                           
    glm::mat4 ModelMatrix,                                      
    float &intersection_distance                                  
);

class PhysicsHandler {
public:
  bool CheckTrigger(CollisionComponent* collider, int trigger_group);

  void RegisterCollider(CollisionComponent* collider);
  void DeregisterCollider(CollisionComponent *collider);
  std::vector<CollisionComponent*>* GetColliders();

  void RegisterTrigger(TriggerComponent* trigger);
  void DeregisterTrigger(TriggerComponent* trigger);
  std::vector<TriggerComponent*>* GetTriggers();

private:
  std::vector<CollisionComponent*> registered_colliders;
  std::vector<TriggerComponent*> registered_triggers;
};


}
