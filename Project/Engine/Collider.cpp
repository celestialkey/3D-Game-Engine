#include "Collider.h"

Collider::Collider(glm::vec3 _pos)
{
	position = _pos;
}

//Plane
void Collider::Init() // Plane (ground);
{
	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(btVector3(position.x, position.y, position.z));
	btStaticPlaneShape *planeShape = new btStaticPlaneShape((btVector3(0, 1, 0)), 0);
	obj.setCollisionShape(planeShape);

	/*btMotionState *motion = new btDefaultMotionState(transform);
	btRigidBody::btRigidBodyConstructionInfo information(_mass, motion, planeShape);
	rb.rigidbody = new btRigidBody(information);
	rb.rigidbody->setCollisionFlags(btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);*/
	Console.message("Static plane collider created.");
}

//Sphere
void Collider::Init(float _rad) // Sphere
{
	radius = _rad;
	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(btVector3(position.x, position.y, position.z));
	btSphereShape *sphereShape = new btSphereShape(_rad);
	obj.setCollisionShape(sphereShape);

	/*btVector3 intertia = btVector3(0, 0, 0);
	if (mass != 0)
	{
	sphereShape->calculateLocalInertia(mass, intertia);
	}
	btMotionState *motion = new btDefaultMotionState(transform);
	btRigidBody::btRigidBodyConstructionInfo information(mass, motion, sphereShape, intertia);
	rb.rigidbody = new btRigidBody(information);*/
	Console.message("Sphere collider created.");
}

//Cylinder
void Collider::Init(float _diameter, float _height) // Cylinder
{
	diameter = _diameter;
	height = _height;
	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(btVector3(position.x, position.y, position.z));
	btCylinderShape* cylinder = new btCylinderShape(btVector3(_diameter / 2.0, _height / 2.0, _diameter / 2.0));
	obj.setCollisionShape(cylinder);

	/*btVector3 inertia(0, 0, 0);
	if (mass != 0.0)
	cylinder->calculateLocalInertia(mass, inertia);

	btMotionState* motion = new btDefaultMotionState(transform);
	btRigidBody::btRigidBodyConstructionInfo info(mass, motion, cylinder, inertia);
	rb.rigidbody = new btRigidBody(info);
	rb.rigidbody->setDamping(0.2, 0.1);*/
	Console.message("Cylinder collider created.");
}

//Box
void Collider::Init(glm::vec3 _size) // Box
{
	/*size.x = _size.x;
	size.y = _size.y;
	size.z = _size.z;
	*/
	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(btVector3(position.x, position.y, position.z));
	btBoxShape* box = new btBoxShape(btVector3(_size.x / 2.0, _size.y / 2.0, _size.z / 2.0));
	obj.setCollisionShape(box);

	/*btVector3 inertia(0, 0, 0);
	if (mass != 0.0)
	box->calculateLocalInertia(mass, inertia);

	btMotionState* motion = new btDefaultMotionState(transform);
	btRigidBody::btRigidBodyConstructionInfo info(mass, motion, box, inertia);
	rb.rigidbody = new btRigidBody(info);*/
	Console.message("Box collider created.");
}
