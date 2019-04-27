
#include "camera.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "../utils/math_utils.h"
using namespace glm;

Camera::Camera(float near, float far, float viewportWidth, float viewportHeight)
    : direction(vec3(0, 0, -1)),
      up(vec3(0, 1, 0)),
      right(vec3(1, 0, 0)),
      near(near), far(far),
      viewportWidth(viewportWidth), viewportHeight(viewportHeight)
{
}

void Camera::lookAt(vec3 target)
{
    lookAt(target, mu::Y);
}

void Camera::lookAt(vec3 target, vec3 localYAxis)
{
    direction = glm::normalize(target - position);
    right = glm::normalize(glm::cross(direction, localYAxis));
    up = glm::normalize(glm::cross(right, direction));
}
