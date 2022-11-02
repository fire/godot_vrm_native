/*************************************************************************/
/* Copyright (c) 2022 K. S. Ernest (iFire) Lee                           */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#pragma once

#include "modules/register_module_types.h"

// #ifdef TOOLS_ENABLED
#include "editor/editor_node.h"

#include "modules/gltf/gltf_document.h"
#include "modules/gltf/gltf_document_extension.h"
#include "modules/gltf/gltf_state.h"

#include "register_types.h"

class vrm_constants_class : public RefCounted {
public:
	Dictionary vrm_to_human_bone;

	vrm_constants_class(bool is_vrm_0) {
		vrm_to_human_bone["hips"] = "Hips";
		vrm_to_human_bone["spine"] = "Spine";
		vrm_to_human_bone["chest"] = "Chest";
		vrm_to_human_bone["upperChest"] = "UpperChest";
		vrm_to_human_bone["neck"] = "Neck";
		vrm_to_human_bone["head"] = "Head";
		vrm_to_human_bone["leftEye"] = "LeftEye";
		vrm_to_human_bone["rightEye"] = "RightEye";
		vrm_to_human_bone["jaw"] = "Jaw";
		vrm_to_human_bone["leftShoulder"] = "LeftShoulder";
		vrm_to_human_bone["leftUpperArm"] = "LeftUpperArm";
		vrm_to_human_bone["leftLowerArm"] = "LeftLowerArm";
		vrm_to_human_bone["leftHand"] = "LeftHand";
		vrm_to_human_bone["leftThumbMetacarpal"] = "LeftThumbMetacarpal";
		vrm_to_human_bone["leftThumbProximal"] = "LeftThumbProximal";
		vrm_to_human_bone["leftThumbDistal"] = "LeftThumbDistal";
		vrm_to_human_bone["leftIndexProximal"] = "LeftIndexProximal";
		vrm_to_human_bone["leftIndexIntermediate"] = "LeftIndexIntermediate";
		vrm_to_human_bone["leftIndexDistal"] = "LeftIndexDistal";
		vrm_to_human_bone["leftMiddleProximal"] = "LeftMiddleProximal";
		vrm_to_human_bone["leftMiddleIntermediate"] = "LeftMiddleIntermediate";
		vrm_to_human_bone["leftMiddleDistal"] = "LeftMiddleDistal";
		vrm_to_human_bone["leftRingProximal"] = "LeftRingProximal";
		vrm_to_human_bone["leftRingIntermediate"] = "LeftRingIntermediate";
		vrm_to_human_bone["leftRingDistal"] = "LeftRingDistal";
		vrm_to_human_bone["leftLittleProximal"] = "LeftLittleProximal";
		vrm_to_human_bone["leftLittleIntermediate"] = "LeftLittleIntermediate";
		vrm_to_human_bone["leftLittleDistal"] = "LeftLittleDistal";
		vrm_to_human_bone["rightShoulder"] = "RightShoulder";
		vrm_to_human_bone["rightUpperArm"] = "RightUpperArm";
		vrm_to_human_bone["rightLowerArm"] = "RightLowerArm";
		vrm_to_human_bone["rightHand"] = "RightHand";
		vrm_to_human_bone["rightThumbMetacarpal"] = "RightThumbMetacarpal";
		vrm_to_human_bone["rightThumbProximal"] = "RightThumbProximal";
		vrm_to_human_bone["rightThumbDistal"] = "RightThumbDistal";
		vrm_to_human_bone["rightIndexProximal"] = "RightIndexProximal";
		vrm_to_human_bone["rightIndexIntermediate"] = "RightIndexIntermediate";
		vrm_to_human_bone["rightIndexDistal"] = "RightIndexDistal";
		vrm_to_human_bone["rightMiddleProximal"] = "RightMiddleProximal";
		vrm_to_human_bone["rightMiddleIntermediate"] = "RightMiddleIntermediate";
		vrm_to_human_bone["rightMiddleDistal"] = "RightMiddleDistal";
		vrm_to_human_bone["rightRingProximal"] = "RightRingProximal";
		vrm_to_human_bone["rightRingIntermediate"] = "RightRingIntermediate";
		vrm_to_human_bone["rightRingDistal"] = "RightRingDistal";
		vrm_to_human_bone["rightLittleProximal"] = "RightLittleProximal";
		vrm_to_human_bone["rightLittleIntermediate"] = "RightLittleIntermediate";
		vrm_to_human_bone["rightLittleDistal"] = "RightLittleDistal";
		vrm_to_human_bone["leftUpperLeg"] = "LeftUpperLeg";
		vrm_to_human_bone["leftLowerLeg"] = "LeftLowerLeg";
		vrm_to_human_bone["leftFoot"] = "LeftFoot";
		vrm_to_human_bone["leftToes"] = "LeftToes";
		vrm_to_human_bone["rightUpperLeg"] = "RightUpperLeg";
		vrm_to_human_bone["rightLowerLeg"] = "RightLowerLeg";
		vrm_to_human_bone["rightFoot"] = "RightFoot";
		vrm_to_human_bone["rightToes"] = "RightToes";
		if (is_vrm_0) {
			vrm_to_human_bone["leftThumbIntermediate"] = "LeftThumbProximal";
			vrm_to_human_bone["leftThumbProximal"] = "LeftThumbMetacarpal";
			vrm_to_human_bone["rightThumbIntermediate"] = "RightThumbProximal";
			vrm_to_human_bone["rightThumbProximal"] = "RightThumbMetacarpal";
		}
	}
};

class VRMTopLevel : public Node3D {
	NodePath vrm_skeleton;
	NodePath vrm_animplayer;
	NodePath vrm_secondary;
	Ref<Resource> vrm_meta;
	bool update_secondary_fixed = false;
	bool update_in_editor = false;
	bool gizmo_spring_bone = false;
	Color gizmo_spring_bone_color = Color(1, 1, 0.878431, 1);

public:
	NodePath get_vrm_skeleton() {
		return vrm_skeleton;
	}
	void set_vrm_skeleton(NodePath p_path) {
		vrm_skeleton = p_path;
	}
	NodePath get_vrm_animplayer() {
		return vrm_animplayer;
	}
	void set_vrm_animplayer(NodePath p_path) {
		vrm_animplayer = p_path;
	}
	NodePath get_vrm_secondary() {
		return vrm_secondary;
	}
	void set_vrm_secondary(NodePath p_path) {
		vrm_secondary = p_path;
	}
	Ref<Resource> get_vrm_meta() {
		return vrm_meta;
	}
	void set_vrm_meta(Ref<Resource> p_meta) {
		vrm_meta = p_meta;
	}
	bool get_update_secondary_fixed() {
		return update_secondary_fixed;
	}
	void set_update_secondary_fixed(bool p_fixed) {
		update_secondary_fixed = p_fixed;
	}
	bool get_update_in_editor() {
		return update_in_editor;
	}
	void set_update_in_editor(bool p_update) {
		update_in_editor = p_update;
	}
	bool get_gizmo_spring_bone() {
		return gizmo_spring_bone;
	}
	void set_gizmo_spring_bone(bool p_update) {
		gizmo_spring_bone = p_update;
	}
	Color get_gizmo_spring_bone_color() {
		return gizmo_spring_bone_color;
	}

protected:
	static void _bind_methods() {
		ClassDB::bind_method(D_METHOD("get_vrm_skeleton"), &VRMTopLevel::get_vrm_skeleton);
		ClassDB::bind_method(D_METHOD("set_vrm_skeleton"), &VRMTopLevel::set_vrm_skeleton);
		ClassDB::bind_method(D_METHOD("get_vrm_animplayer"), &VRMTopLevel::get_vrm_animplayer);
		ClassDB::bind_method(D_METHOD("set_vrm_animplayer"), &VRMTopLevel::set_vrm_animplayer);
		ClassDB::bind_method(D_METHOD("get_vrm_secondary"), &VRMTopLevel::get_vrm_secondary);
		ClassDB::bind_method(D_METHOD("set_vrm_secondary"), &VRMTopLevel::set_vrm_secondary);
		ClassDB::bind_method(D_METHOD("get_update_secondary_fixed"), &VRMTopLevel::get_update_secondary_fixed);
		ClassDB::bind_method(D_METHOD("set_update_secondary_fixed"), &VRMTopLevel::set_update_secondary_fixed);
		ClassDB::bind_method(D_METHOD("get_update_in_editor"), &VRMTopLevel::get_update_in_editor);
		ClassDB::bind_method(D_METHOD("set_update_in_editor"), &VRMTopLevel::set_update_in_editor);
		ClassDB::bind_method(D_METHOD("get_gizmo_spring_bone_color"), &VRMTopLevel::get_gizmo_spring_bone_color);
		ClassDB::bind_method(D_METHOD("set_gizmo_spring_bone_color"), &VRMTopLevel::set_gizmo_spring_bone_color);

		ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "vrm_skeleton"), "set_vrm_skeleton", "get_vrm_skeleton");
		ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "vrm_animplayer"), "set_vrm_animplayer", "get_vrm_animplayer");
		ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "vrm_secondary"), "set_vrm_secondary", "get_vrm_secondary");
		ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "vrm_meta", PROPERTY_HINT_RESOURCE_TYPE, "Resource"), "set_vrm_secondary", "get_vrm_secondary");
		ADD_PROPERTY(PropertyInfo(Variant::BOOL, "update_secondary_fixed"), "set_update_secondary_fixed", "get_update_secondary_fixed");
		ADD_PROPERTY(PropertyInfo(Variant::BOOL, "update_in_editor"), "set_update_in_editor", "get_update_in_editor");
		ADD_PROPERTY(PropertyInfo(Variant::BOOL, "gizmo_spring_bone"), "set_gizmo_spring_bone", "get_gizmo_spring_bone");
		ADD_PROPERTY(PropertyInfo(Variant::COLOR, "gizmo_spring_bone_color"), "set_gizmo_spring_bone_color", "get_gizmo_spring_bone_color");
	}

public:
	void set_gizmo_spring_bone_color(Color p_color) {
		gizmo_spring_bone_color = p_color;
	}
	static Quaternion from_to_rotation(Vector3 from, Vector3 to) {
		Vector3 axis = from.cross(to);
		if (Math::is_equal_approx(axis.x, 0.0f) && Math::is_equal_approx(axis.y, 0.0f) && Math::is_equal_approx(axis.z, 0.0f)) {
			return Quaternion();
		}
		float angle = from.angle_to(to);
		if (Math::is_equal_approx(angle, 0.0f)) {
			angle = 0.0f;
		}
		return Quaternion(axis.normalized(), angle);
	}

	static Vector3 transform_point(Transform3D transform, Vector3 point) {
		Vector3 sc = transform.basis.get_scale();
		return transform.basis.get_rotation_quaternion().xform(Vector3(point.x * sc.x, point.y * sc.y, point.z * sc.z)) + transform.origin;
	}
	static Vector3 inv_transform_point(Transform3D transform, Vector3 point) {
		Vector3 diff = point - transform.origin;
		Vector3 sc = transform.basis.get_scale();
		return transform.basis.get_rotation_quaternion().inverse().xform(Vector3(diff.x / sc.x, diff.y / sc.y, diff.z / sc.z));
	}
};

class SphereCollider : public Resource {
public:
	int idx = -1;
	Vector3 offset;
	float radius = 0.0f;
	Vector3 position;

	void _ready(int bone_idx, Vector3 collider_offset = Vector3(), float collider_radius = 0.1f) {
		// TODO: Do not shadow notification().
		idx = bone_idx;
		offset = collider_offset;
		radius = collider_radius;
	}
	void update(Node3D *parent, Skeleton3D *skel) {
		if (parent->get_class() == "Skeleton3D" && idx != -1) {
			Skeleton3D *skeleton = cast_to<Skeleton3D>(parent);
			position = VRMTopLevel::transform_point(skeleton->get_global_transform() * skel->get_bone_global_pose(idx), offset);
		} else {
			position = VRMTopLevel::transform_point(parent->get_global_transform(), offset);
		}
	}
	float get_radius() {
		return radius;
	}
	Vector3 get_position() {
		return position;
	}
};

// Individual spring bone entries.
class VRMSpringBoneLogic : public RefCounted {
public:
	bool force_update = true;
	int bone_idx = -1;

	float radius = 0;
	float length = 0;

	Vector3 bone_axis;
	Vector3 current_tail;
	Vector3 prev_tail;

	Transform3D initial_transform;

	Transform3D get_transform(Skeleton3D *skel) {
		return skel->get_global_transform() * skel->get_bone_global_pose_no_override(bone_idx);
	}
	Quaternion get_rotation(Skeleton3D *skel) {
		return get_transform(skel).basis.get_rotation_quaternion();
	}

	Transform3D get_local_transform(Skeleton3D *skel) {
		return skel->get_bone_global_pose_no_override(bone_idx);
	}
	Quaternion get_local_rotation(Skeleton3D *skel) {
		return get_local_transform(skel).basis.get_rotation_quaternion();
	}

	void reset(Skeleton3D *skel) {
		skel->set_bone_global_pose_override(bone_idx, initial_transform, 1.0, true);
	}

	void setup(Skeleton3D *skel, int idx, Variant center, Vector3 local_child_position, Transform3D default_pose) {
		initial_transform = default_pose;
		bone_idx = idx;
		Vector3 world_child_position = VRMTopLevel::transform_point(get_transform(skel), local_child_position);
		if (Variant(center).get_type() != Variant::Type::NIL) {
			current_tail = VRMTopLevel::inv_transform_point(center, world_child_position);
		} else {
			current_tail = world_child_position;
		}
		prev_tail = current_tail;
		bone_axis = local_child_position.normalized();
		length = local_child_position.length();
	}

	void update(Skeleton3D *skel, Variant center, float stiffness_force, float drag_force, Vector3 external, Vector<Ref<SphereCollider>> colliders) {
		Vector3 tmp_current_tail;
		Vector3 tmp_prev_tail;
		if (Variant(center).get_type() != Variant::Type::NIL) {
			tmp_current_tail = VRMTopLevel::transform_point(center, current_tail);
			tmp_prev_tail = VRMTopLevel::transform_point(center, prev_tail);
		} else {
			tmp_current_tail = current_tail;
			tmp_prev_tail = prev_tail;
		}

		// Integration of velocity verlet
		Vector3 next_tail = tmp_current_tail + (tmp_current_tail - tmp_prev_tail) * (1.0 - drag_force) + (get_rotation(skel).xform(bone_axis)) * stiffness_force + external;

		// Limiting bone length
		Vector3 origin = get_transform(skel).origin;
		next_tail = origin + (next_tail - origin).normalized() * length;

		// Collision movement
		next_tail = collision(skel, colliders, next_tail);

		// Recording current tails for next process
		if (Variant(center).get_type() != Variant::Type::NIL) {
			prev_tail = VRMTopLevel::inv_transform_point(center, current_tail);
			current_tail = VRMTopLevel::inv_transform_point(center, next_tail);
		} else {
			prev_tail = current_tail;
			current_tail = next_tail;
		}

		// Apply rotation
		Quaternion ft = VRMTopLevel::from_to_rotation((get_rotation(skel).xform(bone_axis)), next_tail - get_transform(skel).origin);
		ft = skel->get_global_transform().basis.get_rotation_quaternion().inverse() * ft;
		Quaternion qt = ft * get_rotation(skel);
		Transform3D local_tr = get_local_transform(skel);
		local_tr.basis = Basis(qt.normalized());
		skel->set_bone_global_pose_override(bone_idx, local_tr, 1.0, true);
	}

	Vector3 collision(Skeleton3D *skel, Vector<Ref<SphereCollider>> colliders, Vector3 next_tail) {
		Vector3 out = next_tail;
		for (Ref<SphereCollider> collider : colliders) {
			real_t r = radius + collider->get_radius();
			Vector3 diff = out - collider->get_position();
			if ((diff.x * diff.x + diff.y * diff.y + diff.z * diff.z) <= r * r) {
				// Hit, move to orientation of normal
				Vector3 normal = (out - collider->get_position()).normalized();
				Vector3 pos_from_collider = collider->get_position() + normal * (radius + collider->get_radius());
				// Limiting bone length
				Vector3 origin = get_transform(skel).origin;
				out = origin + (pos_from_collider - origin).normalized() * length;
			}
		}
		return out;
	}
};

class VRMSpringBone : public Resource {
public:
	// # Annotation comment
	// @export
	String comment;

	// # The resilience of the swaying object (the power of returning to the initial pose).
	// @export_range(0, 4)  var
	float stiffness_force = 1.0f;

	// # The strength of gravity.
	// @export_range(0, 2)  var
	float gravity_power = 0.0f;

	// # The direction of gravity. Set (0, -1, 0) for simulating the gravity.
	// # Set (1, 0, 0) for simulating the wind.
	// @export
	Vector3 gravity_dir = Vector3(0.0, -1.0, 0.0);

	// # The resistance (deceleration) of automatic animation.
	// @export_range(0, 1) var
	float drag_force = 0.4f;

	// # Bone name references are only valid within a given Skeleton.
	// @export
	NodePath skeleton;

	// # The reference point of a swaying object can be set at any location except the origin.
	// # When implementing UI moving with warp, the parent node to move with warp can be
	// # specified if you don't want to make the object swaying with warp movement.",
	// # Exactly one of the following must be set.
	// @export
	String center_bone;
	// @export
	NodePath center_node;

	// # The radius of the sphere used for the collision detection with colliders.
	// @export_range(0.0, 0.5)
	float hit_radius = 0.02f;

	// # bone name of the root bone of the swaying object, within skeleton.
	// @export
	Vector<String> root_bones; // DO NOT INITIALIZE HERE

	// # Reference to the vrm_collidergroup for collisions with swaying objects.
	// @export
	Array collider_groups; // DO NOT INITIALIZE HERE

	// # Props
	Vector<Ref<VRMSpringBoneLogic>> verlets;
	Vector<Ref<SphereCollider>> colliders;
	Variant center;
	Skeleton3D *skel = nullptr;

	void setup(bool force = false) {
		if (!(!root_bones.is_empty() && skel)) {
			return;
		}
		if (!(force || verlets.is_empty())) {
			return;
		}
		if (!verlets.is_empty()) {
			for (Ref<VRMSpringBoneLogic> verlet : verlets) {
				if (verlet.is_null()) {
					continue;
				}
				verlet->reset(skel);
			}
		}
		verlets.clear();
		for (String go : root_bones) {
			if (go.is_empty()) {
				setup_recursive(skel->find_bone(go), center);
			}
		}
	}

	void setup_recursive(int id, Variant center_tr) {
		if (skel->get_bone_children(id).is_empty()) {
			Vector3 delta = skel->get_bone_rest(id).origin;
			Vector3 child_position = delta.normalized() * 0.07;
			Ref<VRMSpringBoneLogic> spring_bone_logic;
			spring_bone_logic.instantiate();
			spring_bone_logic->setup(skel, id, center_tr, child_position, skel->get_bone_global_pose_no_override(id));
			verlets.append(spring_bone_logic);
		} else {
			int first_child = skel->get_bone_children(id)[0];
			Vector3 local_position = skel->get_bone_rest(first_child).origin;
			// TODO: Use full names for variables.
			Vector3 sca = skel->get_bone_rest(first_child).basis.get_scale();
			Vector3 pos = Vector3(local_position.x * sca.x, local_position.y * sca.y, local_position.z * sca.z);
			Ref<VRMSpringBoneLogic> spring_bone_logic;
			spring_bone_logic.instantiate();
			spring_bone_logic->setup(skel, id, center_tr, pos, skel->get_bone_global_pose_no_override(id));
			verlets.append(spring_bone_logic);
		}
		for (int child : skel->get_bone_children(id)) {
			setup_recursive(child, center_tr);
		}
	}

	// Called when the node enters the scene tree for the first time.
	// TODO: Avoid shadowing godot methods.
	void _ready(Skeleton3D *ready_skel, Vector<Ref<SphereCollider>> colliders_ref) {
		if (ready_skel) {
			skel = ready_skel;
		}
		setup();
		colliders = colliders_ref;
	}

	// Called every frame. 'delta' is the elapsed time since the previous frame.
	// TODO: Don't shadow godot methods.
	void _process(double delta) {
		if (verlets.is_empty()) {
			if (root_bones.is_empty()) {
				return;
			}
			setup();
		}
		float stiffness = stiffness_force * delta;
		Vector3 external = gravity_dir * (gravity_power * delta);
		for (Ref<VRMSpringBoneLogic> verlet : verlets) {
			verlet->radius = hit_radius;
			verlet->update(skel, center, stiffness, drag_force, external, colliders);
		}
	}
};

class SecondaryGizmo : public MeshInstance3D {
	Node *secondary_node = nullptr;
	Ref<StandardMaterial3D> m = memnew(StandardMaterial3D);

public:
	SecondaryGizmo(Node *p_parent) {
		set_mesh(memnew(ImmediateMesh));
		secondary_node = p_parent;
		m->set_depth_draw_mode(StandardMaterial3D::DEPTH_DRAW_DISABLED);
		m->set_shading_mode(BaseMaterial3D::SHADING_MODE_UNSHADED);
		m->set_flag(BaseMaterial3D::FLAG_ALBEDO_FROM_VERTEX_COLOR, true);
		m->set_transparency(BaseMaterial3D::TRANSPARENCY_ALPHA);
	}

	void draw_spring_bones(Color color) {
		// set_material_override(m);
		// // Spring bones
		// Array spring_bones_internal_array = secondary_node->get("spring_bones_internal");
		// for (int32_t spring_bone_i = 0; spring_bone_i < spring_bones_internal_array.size(); spring_bone_i++) {
		// 	VRMSpringBone *spring_bone = cast_to<VRMSpringBone>(spring_bones_internal_array[spring_bone_i]);
		// 	Ref<ImmediateMesh> immediate_mesh = get_mesh();
		// 	if (immediate_mesh.is_null()) {
		// 		continue;
		// 	}
		// 	immediate_mesh->surface_begin(Mesh::PRIMITIVE_LINES);
		// 	for (int32_t verlet_i = 0; verlet_i < spring_bone->verlets.size(); verlet_i++) {
		// 		Ref<Resource> v = spring_bone->verlets[verlet_i];
		// 		if (v.is_null()) {
		// 			continue;
		// 		}
		// 		Transform3D s_tr;
		// 		Skeleton3D *s_sk = spring_bone->skel;
		// 		if (Engine::get_singleton()->is_editor_hint() && s_sk) {
		// 			s_sk = secondary_node->get_node_or_null(spring_bone->skeleton);
		// 			if (v.bone_idx != -1) {
		// 				s_tr = s_sk.get_bone_global_pose(v.bone_idx)
		// 			} else {
		// 				s_tr = spring_bone->skel->get_bone_global_pose_no_override(v->bone_idx);
		// 			}
		// 			draw_line(
		// 					s_tr.origin,
		// 					VRMTopLevel.VRMUtil.inv_transform_point(s_sk->get_global_transform(), v.current_tail),
		// 					color);
		// 		}
		// 	}
		// 	immediate_mesh->surface_end();
		// 	for (int32_t verlet_i = 0; verlet_i < spring_bone->verlets.size(); verlet_i++) {
		// 		Ref<Resource> v = spring_bone->verlets[verlet_i];
		// 		if (v.is_null()) {
		// 			continue;
		// 		}
		// 		immediate_mesh->surface_begin(Mesh::PRIMITIVE_LINE_STRIP);
		// 		Transform3D s_tr;
		// 		Skeleton3D *s_sk = spring_bone->skel;
		// 		if (Engine::get_singleton()->is_editor_hint()) {
		// 			s_sk = secondary_node->get_node_or_null(spring_bone->skeleton);
		// 			if (v->bone_idx != -1) {
		// 				s_tr = s_sk->get_bone_global_pose(v.bone_idx);
		// 			}
		// 		} else {
		// 			s_tr = spring_bone.skel->get_bone_global_pose_no_override(v->bone_idx);
		// 		}
		// 		draw_sphere(
		// 				s_tr.basis,
		// 				VRMTopLevel.VRMUtil.inv_transform_point(s_sk->global_transform, v->current_tail),
		// 				spring_bone->hit_radius,
		// 				color);
		// 		immediate_mesh->surface_end();
		// 	}
		// }
	}

	void draw_collider_groups() {
		// Ref<ImmediateMesh> immediate_mesh = get_mesh();
		// if (immediate_mesh.is_null()) {
		// 	return;
		// }
		// set_material_override(m);
		// for (Node *collider_group in (secondary_node.collider_groups ? Engine::get_singleton()->is_editor_hint() : secondary_node->get("collider_groups_internal"))) {
		// 	immediate_mesh->surface_begin(Mesh::PRIMITIVE_LINE_STRIP);
		// 	Transform3D c_tr;
		// 	if (Engine::get_singleton()->is_editor_hint()) {
		// 		Skeleton3D *c_sk = secondary_node.get_node_or_null(collider_group.skeleton_or_node);
		// 		if (c_sk is Skeleton3D) {
		// 			if (collider_group.bone_idx == -1) {
		// 				collider_group.bone_idx = c_sk.find_bone(collider_group.bone);
		// 			}
		// 			c_tr = c_sk.get_bone_global_pose(collider_group.bone_idx);
		// 		}
		// 	} else if (collider_group.parent is Skeleton3D) {
		// 		c_tr = collider_group.skel.get_bone_global_pose_no_override(collider_group.parent.find_bone(collider_group.bone));
		// 	}
		// 	for (collider in collider_group.sphere_colliders) {
		// 		var c_ps : Vector3 = Vector3(0, 0, 0);
		// 		// VRMTopLevel.VRMUtil.coordinate_u2g(collider.normal)
		// 		draw_sphere(c_tr.basis, VRMTopLevel.VRMUtil.transform_point(c_tr, c_ps), collider.d, collider_group.gizmo_color);
		// 	}
		// 	immediate_mesh->surface_end()
		// }
	}

	void draw_line(Vector3 begin_pos, Vector3 end_pos, Color color) {
		Ref<ImmediateMesh> immediate_mesh = get_mesh();
		if (immediate_mesh.is_null()) {
			return;
		}
		immediate_mesh->surface_set_color(color);
		immediate_mesh->surface_add_vertex(begin_pos);
		immediate_mesh->surface_set_color(color);
		immediate_mesh->surface_add_vertex(end_pos);
	}

	void draw_sphere(Basis bas, Vector3 center, float radius, Color color) {
		Ref<ImmediateMesh> immediate_mesh = get_mesh();
		if (immediate_mesh.is_null()) {
			return;
		}
		const int step = 15;
		float sppi = 2.0f * Math_PI / step;
		const Vector3 UP = Vector3(0.0, 1.0, 0.0);
		const Vector3 RIGHT = Vector3(1.0, 0.0, 0.0);
		const Vector3 FORWARD = Vector3(0.0, 0.0, -1.0);
		for (int32_t step_i = 0; step_i < step + 1; step_i++) {
			immediate_mesh->surface_set_color(color);
			immediate_mesh->surface_add_vertex(center + (bas.xform(UP) * radius).rotated(bas.xform(RIGHT), sppi * (step_i % step)));
		}
		for (int32_t step_i = 0; step_i < step + 1; step_i++) {
			immediate_mesh->surface_set_color(color);
			immediate_mesh->surface_add_vertex(center + (bas.xform(RIGHT) * radius).rotated(bas.xform(FORWARD), sppi * (step_i % step)));
		}
		for (int32_t step_i = 0; step_i < step + 1; step_i++) {
			immediate_mesh->surface_set_color(color);
			immediate_mesh->surface_add_vertex(center + (bas.xform(FORWARD) * radius).rotated(bas.xform(UP), sppi * (step_i % step)));
		}
	}
	void draw_in_editor(bool p_do_draw_spring_bones = false) {
		Ref<ImmediateMesh> immediate_mesh = get_mesh();
		if (immediate_mesh.is_valid()) {
			immediate_mesh->clear_surfaces();
		}
		if (!secondary_node) {
			return;
		}
		VRMTopLevel *vrm_top_level = cast_to<VRMTopLevel>(secondary_node->get_parent());
		if (vrm_top_level->get_parent() && vrm_top_level->get_parent()->get("get_gizmo_spring_bone")) {
			draw_spring_bones(vrm_top_level->get_gizmo_spring_bone_color());
			draw_collider_groups();
		}
	}

	void draw_in_game() {
		Ref<ImmediateMesh> immediate_mesh = get_mesh();
		if (immediate_mesh.is_valid()) {
			immediate_mesh->clear_surfaces();
		}
		if (!secondary_node) {
			return;
		}
		VRMTopLevel *vrm_top_level = cast_to<VRMTopLevel>(secondary_node->get_parent());
		if (vrm_top_level->get_parent() && vrm_top_level->get_parent()->get("gizmo_spring_bone")) {
			draw_spring_bones(vrm_top_level->get("gizmo_spring_bone_color"));
			draw_collider_groups();
		}
	}
};

class VRMColliderGroup : public Resource {
public:
	// Bone name references are only valid within the given Skeleton.
	// If the node was not a skeleton, bone is "" and contains a path to the node.
	// @export
	NodePath skeleton_or_node;

	// # The bone within the skeleton with the collider, or "" if not a bone.
	// @export
	String bone;

	// Vector4 = The local coordinate from the node of the collider group in *left-handed* Y-up coordinate and the radius of the collider.
	// The coordinate issue may be fixed in VRM 1.0 or later.
	// https://github.com/vrm-c/vrm-specification/issues/205
	// @export
	Vector<Vector4> sphere_colliders; // DO NOT INITIALIZE HERE

	// # Only use in editor
	// @export
	Color gizmo_color = Color::hex(0XFF00FFFF);

	// # Props
	Vector<Ref<SphereCollider>> colliders;
	int bone_idx = -1;
	Node3D *parent = nullptr;

	Skeleton3D *skel = nullptr;

	void setup() {
		if (parent == nullptr) {
			return;
		}
		colliders.clear();
		for (const Vector4 &collider : sphere_colliders) {
			Ref<SphereCollider> collider_single;
			collider_single.instantiate();
			collider_single->_ready(bone_idx, Vector3(collider.x, collider.y, collider.z), collider.w);
			colliders.append(collider_single);
		}
	}
	void _ready(Node3D *ready_parent, Skeleton3D *ready_skel) {
		// TODO: Why is there a duplicate variable here?
		parent = ready_parent;
		if (ready_parent->get_class() == "Skeleton3D") {
			skel = ready_skel;
			bone_idx = cast_to<Skeleton3D>(ready_parent)->find_bone(bone);
		}
		setup();
	}
	void _process() {
		for (Ref<SphereCollider> collider : colliders) {
			collider->update(parent, skel);
		}
	}
};

class VRMSecondary : public Node3D {
public:
	//@export
	Vector<Ref<VRMSpringBone>> spring_bones;
	// @export
	Vector<Ref<VRMColliderGroup>> collider_groups;

	bool update_secondary_fixed = false;
	bool update_in_editor = false;

private:
	Vector<Ref<VRMSpringBone>> spring_bones_internal;
	Vector<Ref<VRMColliderGroup>> collider_groups_internal;
	SecondaryGizmo *secondary_gizmo = nullptr;

protected:
	void _notification(int p_what) {
		switch (p_what) {
			case NOTIFICATION_READY: {
				bool gizmo_spring_bone = false;
				VRMTopLevel *vrm_top_level = cast_to<VRMTopLevel>(get_parent());
				if (vrm_top_level) {
					update_secondary_fixed = vrm_top_level->get_update_secondary_fixed();
					gizmo_spring_bone = vrm_top_level->get_gizmo_spring_bone();
				}
				if (secondary_gizmo == nullptr && (Engine::get_singleton()->is_editor_hint() || gizmo_spring_bone)) {
					secondary_gizmo = memnew(SecondaryGizmo(this));
					add_child(secondary_gizmo, true);
				}
				collider_groups_internal.clear();
				spring_bones_internal.clear();
				for (Ref<VRMColliderGroup> collider_group : collider_groups) {
					Ref<VRMColliderGroup> new_collider_group = collider_group->duplicate(true);
					Skeleton3D *parent = cast_to<Skeleton3D>(get_node_or_null(new_collider_group->skeleton_or_node));
					if (parent) {
						new_collider_group->_ready(parent, parent);
						collider_groups_internal.append(new_collider_group);
					}
				}
				for (Ref<VRMSpringBone> spring_bone : spring_bones) {
					Ref<VRMSpringBone> new_spring_bone = spring_bone->duplicate(true);
					Vector<Ref<SphereCollider>> tmp_colliders;
					for (int32_t collider_i = 0; collider_i < collider_groups.size(); collider_i++) {
						if (new_spring_bone->collider_groups.has(collider_groups[collider_i])) {
							tmp_colliders.append_array(collider_groups_internal[collider_i]->colliders);
						}
					}
					Skeleton3D *skel = cast_to<Skeleton3D>(get_node_or_null(new_spring_bone->skeleton));
					if (skel) {
						new_spring_bone->_ready(skel, tmp_colliders);
						spring_bones_internal.append(new_spring_bone);
					}
				}
			} break;
			case NOTIFICATION_PROCESS: {
				if (!update_secondary_fixed) {
					return;
				}
				if (!Engine::get_singleton()->is_editor_hint() || check_for_editor_update()) {
					// Force update the skeleton.
					for (Ref<VRMSpringBone> spring_bone : spring_bones_internal) {
						if (spring_bone->skel) {
							spring_bone->skel->get_bone_global_pose_no_override(0);
						}
					}
					for (Ref<VRMColliderGroup> collider_group : collider_groups_internal) {
						collider_group->_process();
					}
					for (Ref<VRMSpringBone> spring_bone : spring_bones_internal) {
						spring_bone->_process(get_process_delta_time());
					}
					if (secondary_gizmo) {
						if (Engine::get_singleton()->is_editor_hint()) {
							secondary_gizmo->draw_in_editor(true);
						} else {
							secondary_gizmo->draw_in_game();
						}
					}
				} else if (Engine::get_singleton()->is_editor_hint()) {
					if (secondary_gizmo) {
						secondary_gizmo->draw_in_editor();
					}
				}
			} break;
			case NOTIFICATION_PHYSICS_PROCESS: {
				if (!update_secondary_fixed) {
					return;
				}
				if (!Engine ::get_singleton()->is_editor_hint() || check_for_editor_update()) {
					// Force the skeleton update.
					for (Ref<VRMSpringBone> spring_bone : spring_bones_internal) {
						if (spring_bone->skel) {
							spring_bone->skel->get_bone_global_pose_no_override(0);
						}
					}
					for (Ref<VRMColliderGroup> collider_group : collider_groups_internal) {
						collider_group->_process();
					}
					for (Ref<VRMSpringBone> spring_bone : spring_bones_internal) {
						spring_bone->_process(get_physics_process_delta_time());
					}
					if (secondary_gizmo) {
						if (Engine::get_singleton()->is_editor_hint()) {
							secondary_gizmo->draw_in_editor(true);
						} else {
							secondary_gizmo->draw_in_game();
						}
					} else if (Engine::get_singleton()->is_editor_hint()) {
						if (secondary_gizmo) {
							secondary_gizmo->draw_in_editor();
						}
					}
				}
			} break;
		}
	}

public:
	bool check_for_editor_update() {
		if (!Engine::get_singleton()->is_editor_hint()) {
			return false;
		}
		Node *parent = get_parent();
		VRMTopLevel *vrm_top_level = cast_to<VRMTopLevel>(parent);
		if (vrm_top_level) {
			if (vrm_top_level->get_update_in_editor() && !update_in_editor) {
				update_in_editor = true;
				_notification(NOTIFICATION_READY);
			}
		}
		if (!parent->get("update_in_editor") && update_in_editor) {
			update_in_editor = false;
			for (Ref<VRMSpringBone> spring_bone : spring_bones_internal) {
				spring_bone->skel->clear_bones_global_pose_override();
			}
		}
		return update_in_editor;
	}
};

class VRMMeta : public Resource {
public:
	// VRM extension is for 3d humanoid avatars (and models) in VR applications.
	// Meta schema:

	//Title of VRM model
	String title;

	//Version of VRM model
	String version;

	//Author of VRM model
	String author;

	//Contact Information of VRM model author
	String contact_information;

	//Reference of VRM model
	String reference_information;

	// Thumbnail of VRM model
	Ref<Texture2D> texture;

	//A person who can perform with this avatar
	String allowed_user_name;
	// (String,"","OnlyAuthor","ExplicitlyLicensedPerson","Everyone")
	//Permission to perform violent acts with this avatar
	String violent_usage;
	// (String,"","Disallow","Allow")
	//Permission to perform sexual acts with this avatar
	String sexual_usage;
	// (String,"","Disallow","Allow")
	//For commercial use
	String commercial_usage;
	// (String,"","Disallow","Allow")
	//If there are any conditions not mentioned above, put the URL link of the license document here.
	String other_permission_url;

	//License type
	String license_name;
	// (String,"","Redistribution_Prohibited","CC0","CC_BY","CC_BY_NC","CC_BY_SA","CC_BY_NC_SA","CC_BY_ND","CC_BY_NC_ND","Other")
	//If "Other" is selected, put the URL link of the license document here.
	String other_license_url;

	//Human bone name -> Reference node index
	//NOTE: We are currently discarding all Unity-specific data.
	//We may need to store it somewhere in case we wish to re-export.
	Ref<BoneMap> humanoid_bone_mapping; // VRM boneName -> bone name (within skeleton)

	NodePath humanoid_skeleton_path;

	//firstPersonBoneOffset:
	//The target position of the VR headset in first-person view.
	//It is assumed that an offset from the head bone to the VR headset is added.
	Vector3 eye_offset;
	//NOTE: Mouth offset is not stored in any model metadata.
	//As an alternative, we could get the centroid of vertices moved by viseme blend shapes.
	//But for now, users should assume same as eyeOffset with y=0 (relative to head)

	//Toplevel schema, belongs in vrm_meta:
	//Version of exporter that vrm created. UniVRM-0.46
	String exporter_version;

	//Version of VRM specification. 0.0
	String spec_version;
};

class VRMEditorSceneFormatImporter : public EditorSceneFormatImporter {
public:
	virtual uint32_t get_import_flags() const { return IMPORT_SCENE; }
	virtual void get_extensions(List<String> *r_extensions) const {
		r_extensions->push_back("vrm");
	}

public:
	Ref<Resource> vrm_met;
	const Basis ROTATE_180_BASIS = Basis(Vector3(-1, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, -1));
	const Transform3D ROTATE_180_TRANSFORM = Transform3D(ROTATE_180_BASIS, Vector3());

	void adjust_mesh_zforward(Ref<ImporterMesh> mesh) {
		// MESH and SKIN data divide, to compensate for object position multiplying.
		int surf_count = mesh->get_surface_count();
		Array surf_data_by_mesh;
		Vector<String> blendshapes;
		for (int32_t bsidx = 0; bsidx < mesh->get_blend_shape_count(); bsidx++) {
			blendshapes.append(mesh->get_blend_shape_name(bsidx));
		}
		for (int32_t surf_idx = 0; surf_idx < surf_count; surf_idx++) {
			int prim = mesh->get_surface_primitive_type(surf_idx);
			int fmt_compress_flags = mesh->get_surface_format(surf_idx);
			Array arr = mesh->get_surface_arrays(surf_idx);
			String name = mesh->get_surface_name(surf_idx);
			int32_t bscount = mesh->get_blend_shape_count();
			Array bsarr;
			for (int32_t bsidx = 0; bsidx < bscount; bsidx++) {
				bsarr.append(mesh->get_surface_blend_shape_arrays(surf_idx, bsidx));
			}
			// TODO: RESTORE LODS.
			Dictionary lods; // mesh.surface_get_lods(surf_idx) # get_lods(mesh, surf_idx);
			Ref<Material> mat = mesh->get_surface_material(surf_idx);
			Vector<Vector3> vertarr = arr[ArrayMesh::ARRAY_VERTEX];
			for (int32_t i = 0; i < vertarr.size(); i++) {
				vertarr.write[i] = Vector3(-1, 1, -1) * vertarr[i];
			}
			if (Variant(arr[ArrayMesh::ARRAY_NORMAL]).get_type() == Variant::Type::PACKED_VECTOR3_ARRAY) {
				Vector<Vector3> normarr = arr[ArrayMesh::ARRAY_NORMAL];
				for (int32_t i = 0; i < normarr.size(); i++) {
					normarr.write[i] = Vector3(-1, 1, -1) * normarr[i];
				}
			}
			if (Variant(arr[ArrayMesh::ARRAY_TANGENT]).get_type() == Variant::Type::PACKED_FLOAT32_ARRAY) {
				Vector<float> tangarr = arr[ArrayMesh::ARRAY_TANGENT];
				for (int32_t i = 0; i < tangarr.size(); i++) {
					ERR_BREAK(i * 4 >= tangarr.size());
					ERR_BREAK((i * 4) + 2 >= tangarr.size());
					tangarr.write[i * 4] = -tangarr[i * 4];
					tangarr.write[i * 4 + 2] = -tangarr[i * 4 + 2];
				}
			}
			for (int32_t bsidx = 0; bsidx < bsarr.size(); bsidx++) {
				Array blend_shape_mesh_array;
				blend_shape_mesh_array.resize(ArrayMesh::ARRAY_MAX);
				vertarr = blend_shape_mesh_array[ArrayMesh::ARRAY_VERTEX];
				for (int32_t i = 0; i < vertarr.size(); i++) {
					vertarr.write[i] = Vector3(-1, 1, -1) * vertarr[i];
				}
				if (Variant(blend_shape_mesh_array[ArrayMesh::ARRAY_NORMAL]).get_type() == Variant::Type::PACKED_VECTOR3_ARRAY) {
					Vector<Vector3> normarr = blend_shape_mesh_array[ArrayMesh::ARRAY_NORMAL];
					for (int32_t i = 0; i < normarr.size(); i++) {
						ERR_BREAK(i >= normarr.size());
						normarr.write[i] = Vector3(-1, 1, -1) * normarr[i];
					}
				}
				if (Variant(blend_shape_mesh_array[ArrayMesh::ARRAY_TANGENT]).get_type() == Variant::Type::PACKED_FLOAT32_ARRAY) {
					Vector<float> tangarr = blend_shape_mesh_array[ArrayMesh::ARRAY_TANGENT];
					for (int32_t i = 0; i < tangarr.size(); i++) {
						ERR_BREAK(i * 4 >= tangarr.size());
						ERR_BREAK((i * 4) + 2 >= tangarr.size());
						tangarr.write[i * 4] = -tangarr[i * 4];
						tangarr.write[i * 4 + 2] = -tangarr[i * 4 + 2];
					}
				}
				bsarr[bsidx] = blend_shape_mesh_array;
			}
			Dictionary surf_data;
			surf_data["prim"] = prim;
			surf_data["arr"] = arr;
			surf_data["bsarr"] = bsarr;
			surf_data["lods"] = lods;
			surf_data["fmt_compress_flags"] = fmt_compress_flags;
			surf_data["name"] = name;
			surf_data["mat"] = mat;
			surf_data_by_mesh.push_back(surf_data);
		}
		mesh->clear();
		for (String blend_name : blendshapes) {
			mesh->add_blend_shape(blend_name);
		}
		for (int32_t surf_idx = 0; surf_idx < surf_count; surf_idx++) {
			int prim = surf_data_by_mesh[surf_idx].get("prim");
			Array arr = surf_data_by_mesh[surf_idx].get("arr");
			Array bsarr = surf_data_by_mesh[surf_idx].get("bsarr");
			Dictionary lods = surf_data_by_mesh[surf_idx].get("lods");
			int fmt_compress_flags = surf_data_by_mesh[surf_idx].get("fmt_compress_flags");
			String name = surf_data_by_mesh[surf_idx].get("name");
			Ref<Material> mat = surf_data_by_mesh[surf_idx].get("mat");
			mesh->add_surface(Mesh::PrimitiveType(prim), arr, bsarr, lods, mat, name, fmt_compress_flags);
		}
	}
	void skeleton_rename(Ref<GLTFState> gstate, Node *p_base_scene, Skeleton3D *p_skeleton, Ref<BoneMap> p_bone_map) {
		ERR_FAIL_NULL(p_skeleton);
		ERR_FAIL_NULL(p_bone_map);
		ERR_FAIL_NULL(p_base_scene);
		ERR_FAIL_NULL(gstate);
		int skellen = p_skeleton->get_bone_count();
		for (int32_t bone_i = 0; bone_i < skellen; bone_i++) {
			StringName bn = p_bone_map->find_profile_bone_name(p_skeleton->get_bone_name(bone_i));
			if (bn != StringName()) {
				p_skeleton->set_bone_name(bone_i, bn);
			}
		}
		TypedArray<GLTFNode> gnodes = gstate->get_nodes();
		for (int32_t node_i = 0; node_i < gnodes.size(); node_i++) {
			Ref<GLTFNode> gnode = gnodes[node_i];
			if (gnode.is_null()) {
				continue;
			}
			StringName bn = p_bone_map->find_profile_bone_name(gnode->get_name());
			if (bn != StringName()) {
				gnode->set_name(bn);
			}
		}
		TypedArray<Node> nodes = p_base_scene->find_children("*", "ImporterMeshInstance3D");
		while (!nodes.is_empty()) {
			ImporterMeshInstance3D *mi = cast_to<ImporterMeshInstance3D>(nodes.pop_back());
			Ref<Skin> skin = mi->get_skin();
			if (skin.is_null()) {
				continue;
			}
			Node *node = mi->get_node(mi->get_skeleton_path());
			if (node && cast_to<Skeleton3D>(node) && node == p_skeleton) {
				skellen = skin->get_bind_count();
				for (int32_t bone_i = 0; bone_i < skellen; bone_i++) {
					StringName bn = p_bone_map->find_profile_bone_name(skin->get_bind_name(bone_i));
					if (bn != StringName()) {
						skin->set_bind_name(bone_i, bn);
					}
				}
			}
		}
		// Rename bones in all Nodes by calling method.
		nodes = p_base_scene->find_children("*");
		while (!nodes.is_empty()) {
			Node *nd = cast_to<Node>(nodes.pop_back());
			if (nd->has_method("_notify_skeleton_bones_renamed")) {
				nd->call("_notify_skeleton_bones_renamed", p_base_scene, p_skeleton, p_bone_map);
			}
		}
		p_skeleton->set_name("GeneralSkeleton");
		p_skeleton->set_unique_name_in_owner(true);
	}

	void rotate_scene_180_inner(Node3D *p_node, Dictionary &mesh_set, Dictionary &skin_set) {
		ERR_FAIL_NULL(p_node);
		Skeleton3D *skeleton = cast_to<Skeleton3D>(p_node);
		if (skeleton) {
			for (int32_t bone_idx = 0; bone_idx < skeleton->get_bone_count(); bone_idx++) {
				Transform3D rest = ROTATE_180_TRANSFORM * skeleton->get_bone_rest(bone_idx) * ROTATE_180_TRANSFORM;
				skeleton->set_bone_rest(bone_idx, rest);
				skeleton->set_bone_pose_rotation(bone_idx, Quaternion(ROTATE_180_BASIS) * skeleton->get_bone_pose_rotation(bone_idx) * Quaternion(ROTATE_180_BASIS));
				skeleton->set_bone_pose_scale(bone_idx, Vector3(1.0f, 1.0f, 1.0f));
				skeleton->set_bone_pose_position(bone_idx, rest.origin);
			}
		}
		p_node->get_transform() = ROTATE_180_TRANSFORM * p_node->get_transform() * ROTATE_180_TRANSFORM;
		ImporterMeshInstance3D *importer_mesh_instance_3d = cast_to<ImporterMeshInstance3D>(p_node);
		if (importer_mesh_instance_3d) {
			mesh_set[importer_mesh_instance_3d->get_mesh()] = true;
			skin_set[importer_mesh_instance_3d->get_skin()] = true;
		}
		for (int32_t child_i = 0; child_i < p_node->get_child_count(); child_i++) {
			Node3D *child = cast_to<Node3D>(p_node->get_child(child_i));
			rotate_scene_180_inner(child, mesh_set, skin_set);
		}
	}

	void rotate_scene_180(Node3D *p_scene) {
		Dictionary mesh_set;
		Dictionary skin_set;
		rotate_scene_180_inner(p_scene, mesh_set, skin_set);
		for (int32_t mesh_i = 0; mesh_i < mesh_set.keys().size(); mesh_i++) {
			Ref<ImporterMesh> mesh = mesh_set.keys()[mesh_i];
			adjust_mesh_zforward(mesh);
		}
		for (int32_t skin_i = 0; skin_i < skin_set.keys().size(); skin_i++) {
			Ref<Skin> skin = skin_set.keys()[skin_i];
			if (skin.is_null()) {
				continue;
			}
			for (int32_t bind_i = 0; bind_i < skin->get_bind_count(); bind_i++) {
				skin->set_bind_pose(bind_i, ROTATE_180_TRANSFORM * skin->get_bind_pose(bind_i));
			}
		}
	}

	TypedArray<Basis> skeleton_rotate(Node *p_base_scene, Skeleton3D *src_skeleton, Ref<BoneMap> p_bone_map) {
		Ref<SkeletonProfile> profile = p_bone_map->get_profile();
		Skeleton3D *prof_skeleton = memnew(Skeleton3D);
		for (int32_t bone_i = 0; bone_i < profile->get_bone_size(); bone_i++) {
			StringName bone_name = profile->get_bone_name(bone_i);
			if (prof_skeleton->find_bone(bone_name) != -1) {
				continue;
			}
			// Add single bones.
			prof_skeleton->add_bone(bone_name);
			prof_skeleton->set_bone_rest(bone_i, profile->get_reference_pose(bone_i));
		}
		for (int32_t bone_i = 0; bone_i < profile->get_bone_size(); bone_i++) {
			// Set parents.
			int32_t parent = prof_skeleton->find_bone(profile->get_bone_parent(bone_i));
			if (parent >= 0) {
				prof_skeleton->set_bone_parent(bone_i, parent);
			}
		}
		// Overwrite axis.
		TypedArray<Transform3D> old_skeleton_rest;
		TypedArray<Transform3D> old_skeleton_global_rest;
		for (int32_t bone_i = 0; bone_i < src_skeleton->get_bone_count(); bone_i++) {
			old_skeleton_rest.push_back(src_skeleton->get_bone_rest(bone_i));
			old_skeleton_global_rest.push_back(src_skeleton->get_bone_global_rest(bone_i));
		}
		TypedArray<Basis> diffs;
		diffs.resize(src_skeleton->get_bone_count());
		PackedInt32Array bones_to_process = src_skeleton->get_parentless_bones();
		int32_t bpidx = 0;
		while (bpidx < bones_to_process.size()) {
			int src_idx = bones_to_process[bpidx];
			bpidx += 1;
			Vector<int> src_children = src_skeleton->get_bone_children(src_idx);
			for (int32_t bone_i = 0; bone_i < src_children.size(); bone_i++) {
				bones_to_process.push_back(src_children[bone_i]);
			}
			Basis tgt_rot;
			String src_bone_name = src_skeleton->get_bone_name(src_idx);
			if (!src_bone_name.is_empty()) {
				Basis src_pg;
				int src_parent_idx = src_skeleton->get_bone_parent(src_idx);
				if (src_parent_idx >= 0) {
					src_pg = src_skeleton->get_bone_global_rest(src_parent_idx).basis;
				}
				int prof_idx = profile->find_bone(src_bone_name);
				if (prof_idx >= 0) {
					tgt_rot = src_pg.inverse() * prof_skeleton->get_bone_global_rest(prof_idx).basis; // Mapped bone uses reference pose.
				}
			}
			if (src_skeleton->get_bone_parent(src_idx) >= 0) {
				diffs[src_idx] = tgt_rot.inverse() * Basis(diffs[src_skeleton->get_bone_parent(src_idx)]) * src_skeleton->get_bone_rest(src_idx).basis;
			} else {
				diffs[src_idx] = tgt_rot.inverse() * src_skeleton->get_bone_rest(src_idx).basis;
			}
			Basis diff;
			if (src_skeleton->get_bone_parent(src_idx) >= 0) {
				diff = diffs[src_skeleton->get_bone_parent(src_idx)];
			}
			src_skeleton->set_bone_rest(src_idx, Transform3D(tgt_rot, diff.xform(src_skeleton->get_bone_rest(src_idx).origin)));
		}
		prof_skeleton->queue_free();
		return diffs;
	}

	void apply_rotation(Node *p_base_scene, Skeleton3D *src_skeleton) {
		// 	# Fix skin.
		// 	var nodes: Array[Node] = p_base_scene.find_children("*", "ImporterMeshInstance3D")
		// 	while not nodes.is_empty():
		// 		var this_node = nodes.pop_back()
		// 		if this_node is ImporterMeshInstance3D:
		// 			var mi = this_node
		// 			var skin: Skin = mi.skin
		// 			var node = mi.get_node_or_null(mi.skeleton_path)
		// 			if skin and node and node is Skeleton3D and node == src_skeleton:
		// 				var skellen = skin.get_bind_count()
		// 				for i in range(skellen):
		// 					var bn: StringName = skin.get_bind_name(i);
		// 					var bone_idx: int = src_skeleton.find_bone(bn);
		// 					if bone_idx >= 0:
		// 						# silhouette_diff[i] *
		// 						# Normally would need to take bind-pose into account.
		// 						# However, in this case, it works because VRM files must be baked before export.
		// 						var new_rest: Transform3D = src_skeleton.get_bone_global_rest(bone_idx)
		// 						skin.set_bind_pose(i, new_rest.inverse())

		// 	# Init skeleton pose to new rest.
		// 	for i in range(src_skeleton.get_bone_count()):
		// 		var fixed_rest: Transform3D = src_skeleton.get_bone_rest(i)
		// 		src_skeleton.set_bone_pose_position(i, fixed_rest.origin)
		// 		src_skeleton.set_bone_pose_rotation(i, fixed_rest.basis.get_rotation_quaternion())
		// 		src_skeleton.set_bone_pose_scale(i, fixed_rest.basis.get_scale())
	}

	// enum DebugMode {
	// 	None = 0,
	// 	Normal = 1,
	// 	LitShadeRate = 2,
	// }

	// enum OutlineColorMode {
	// 	FixedColor = 0,
	// 	MixedLight3Ding = 1,
	// }

	// enum OutlineWidthMode {
	// 	None = 0,
	// 	WorldCoordinates = 1,
	// 	ScreenCoordinates = 2,
	// }

	// enum RenderMode {
	// 	Opaque = 0,
	// 	Cutout = 1,
	// 	Transparent = 2,
	// 	TransparentWithZWrite = 3,
	// }

	// enum CullMode {
	// 	Off = 0,
	// 	Front = 1,
	// 	Back = 2,
	// }

	// enum FirstPersonFlag {
	// 	Auto, # Create headlessModel
	// 	Both, # Default layer
	// 	ThirdPersonOnly,
	// 	FirstPersonOnly,
	// }
	// const FirstPersonParser: Dictionary = {
	// 	"Auto": FirstPersonFlag.Auto,
	// 	"Both": FirstPersonFlag.Both,
	// 	"FirstPersonOnly": FirstPersonFlag.FirstPersonOnly,
	// 	"ThirdPersonOnly": FirstPersonFlag.ThirdPersonOnly,
	// }

	// func _process_khr_material(orig_mat: StandardMaterial3D, gltf_mat_props: Dictionary) -> Material:
	// 	# VRM spec requires support for the KHR_materials_unlit extension.
	// 	if gltf_mat_props.has("extensions"):
	// 		# TODO: Implement this extension upstream.
	// 		if gltf_mat_props["extensions"].has("KHR_materials_unlit"):
	// 			# TODO: validate that this is sufficient.
	// 			orig_mat.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	// 	return orig_mat

	// func _vrm_get_texture_info(gltf_images: Array, vrm_mat_props: Dictionary, unity_tex_name: String) -> Dictionary:
	// 	var texture_info: Dictionary = {}
	// 	texture_info["tex"] = null
	// 	texture_info["offset"] = Vector3(0.0, 0.0, 0.0)
	// 	texture_info["scale"] = Vector3(1.0, 1.0, 1.0)
	// 	if vrm_mat_props["textureProperties"].has(unity_tex_name):
	// 		var mainTexId: int = vrm_mat_props["textureProperties"][unity_tex_name]
	// 		var mainTexImage: Texture2D = gltf_images[mainTexId]
	// 		texture_info["tex"] = mainTexImage
	// 	if vrm_mat_props["vectorProperties"].has(unity_tex_name):
	// 		var offsetScale: Array = vrm_mat_props["vectorProperties"][unity_tex_name]
	// 		texture_info["offset"] = Vector3(offsetScale[0], offsetScale[1], 0.0)
	// 		texture_info["scale"] = Vector3(offsetScale[2], offsetScale[3], 1.0)
	// 	return texture_info

	// func _vrm_get_float(vrm_mat_props: Dictionary, key: String, def: float) -> float:
	// 	return vrm_mat_props["floatProperties"].get(key, def)

	// func _process_vrm_material(orig_mat: StandardMaterial3D, gltf_images: Array, vrm_mat_props: Dictionary) -> Material:
	// 	var vrm_shader_name:String = vrm_mat_props["shader"]
	// 	if vrm_shader_name == "VRM_USE_GLTFSHADER":
	// 		return orig_mat # It's already correct!

	// 	if (vrm_shader_name == "Standard" or
	// 		vrm_shader_name == "UniGLTF/UniUnlit"):
	// 		printerr("Unsupported legacy VRM shader " + vrm_shader_name + " on material " + str(orig_mat.resource_name))
	// 		return orig_mat

	// 	var maintex_info: Dictionary = _vrm_get_texture_info(gltf_images, vrm_mat_props, "_MainTex")

	// 	if (vrm_shader_name == "VRM/UnlitTransparentZWrite" or vrm_shader_name == "VRM/UnlitTransparent" or
	// 			vrm_shader_name == "VRM/UnlitTexture" or vrm_shader_name == "VRM/UnlitCutout"):
	// 		if maintex_info["tex"] != null:
	// 			orig_mat.albedo_texture = maintex_info["tex"]
	// 			orig_mat.uv1_offset = maintex_info["offset"]
	// 			orig_mat.uv1_scale = maintex_info["scale"]
	// 		orig_mat.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	// 		if vrm_shader_name == "VRM/UnlitTransparentZWrite":
	// 			orig_mat.depth_draw_mode = StandardMaterial3D.DEPTH_DRAW_ALWAYS
	// 		orig_mat.no_depth_test = false
	// 		if vrm_shader_name == "VRM/UnlitTransparent" or vrm_shader_name == "VRM/UnlitTransparentZWrite":
	// 			orig_mat.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
	// 			orig_mat.blend_mode = StandardMaterial3D.BLEND_MODE_MIX
	// 		if vrm_shader_name == "VRM/UnlitCutout":
	// 			orig_mat.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA_SCISSOR
	// 			orig_mat.alpha_scissor_threshold = _vrm_get_float(vrm_mat_props, "_Cutoff", 0.5)
	// 		return orig_mat

	// 	if vrm_shader_name != "VRM/MToon":
	// 		printerr("Unknown VRM shader " + vrm_shader_name + " on material " + str(orig_mat.resource_name))
	// 		return orig_mat

	// 	# Enum(Off,0,Front,1,Back,2) _CullMode

	// 	var outline_width_mode = int(vrm_mat_props["floatProperties"].get("_OutlineWidthMode", 0))
	// 	var blend_mode = int(vrm_mat_props["floatProperties"].get("_BlendMode", 0))
	// 	var cull_mode = int(vrm_mat_props["floatProperties"].get("_CullMode", 2))
	// 	var outl_cull_mode = int(vrm_mat_props["floatProperties"].get("_OutlineCullMode", 1))
	// 	if cull_mode == int(CullMode.Front) || (outl_cull_mode != int(CullMode.Front) && outline_width_mode != int(OutlineWidthMode.None)):
	// 		printerr("VRM Material " + str(orig_mat.resource_name) + " has unsupported front-face culling mode: " +
	// 			str(cull_mode) + "/" + str(outl_cull_mode))

	// 	var mtoon_shader_base_path = "res://addons/Godot-MToon-Shader/mtoon"

	// 	var godot_outline_shader_name = null
	// 	if outline_width_mode != int(OutlineWidthMode.None):
	// 		godot_outline_shader_name = mtoon_shader_base_path + "_outline"

	// 	var godot_shader_name = mtoon_shader_base_path
	// 	if blend_mode == int(RenderMode.Opaque) or blend_mode == int(RenderMode.Cutout):
	// 		# NOTE: Cutout is not separately implemented due to code duplication.
	// 		if cull_mode == int(CullMode.Off):
	// 			godot_shader_name = mtoon_shader_base_path + "_cull_off"
	// 	elif blend_mode == int(RenderMode.Transparent):
	// 		godot_shader_name = mtoon_shader_base_path + "_trans"
	// 		if cull_mode == int(CullMode.Off):
	// 			godot_shader_name = mtoon_shader_base_path + "_trans_cull_off"
	// 	elif blend_mode == int(RenderMode.TransparentWithZWrite):
	// 		godot_shader_name = mtoon_shader_base_path + "_trans_zwrite"
	// 		if cull_mode == int(CullMode.Off):
	// 			godot_shader_name = mtoon_shader_base_path + "_trans_zwrite_cull_off"

	// 	var godot_shader: Shader = ResourceLoader.load(godot_shader_name + ".gdshader")
	// 	var godot_shader_outline: Shader = null
	// 	if godot_outline_shader_name:
	// 		godot_shader_outline = ResourceLoader.load(godot_outline_shader_name + ".gdshader")

	// 	var new_mat = ShaderMaterial.new()
	// 	new_mat.resource_name = orig_mat.resource_name
	// 	new_mat.shader = godot_shader
	// 	if maintex_info.get("tex", null) != null:
	// 		new_mat.set_shader_parameter("_MainTex", maintex_info["tex"])

	// 	new_mat.set_shader_parameter("_MainTex_ST", Plane(
	// 		maintex_info["scale"].x, maintex_info["scale"].y,
	// 		maintex_info["offset"].x, maintex_info["offset"].y))

	// 	for param_name in ["_MainTex", "_ShadeTexture", "_BumpMap", "_RimTexture", "_SphereAdd", "_EmissionMap", "_OutlineWidthTexture", "_UvAnimMaskTexture"]:
	// 		var tex_info: Dictionary = _vrm_get_texture_info(gltf_images, vrm_mat_props, param_name)
	// 		if tex_info.get("tex", null) != null:
	// 			new_mat.set_shader_parameter(param_name, tex_info["tex"])

	// 	for param_name in vrm_mat_props["floatProperties"]:
	// 		new_mat.set_shader_parameter(param_name, vrm_mat_props["floatProperties"][param_name])

	// 	for param_name in ["_Color", "_ShadeColor", "_RimColor", "_EmissionColor", "_OutlineColor"]:
	// 		if param_name in vrm_mat_props["vectorProperties"]:
	// 			var param_val = vrm_mat_props["vectorProperties"][param_name]
	// 			#### TODO: Use Color
	// 			### But we want to keep 4.0 compat which does not gamma correct color.
	// 			var color_param: Plane = Plane(param_val[0], param_val[1], param_val[2], param_val[3])
	// 			new_mat.set_shader_parameter(param_name, color_param)

	// 	# FIXME: setting _Cutoff to disable cutoff is a bit unusual.
	// 	if blend_mode == int(RenderMode.Cutout):
	// 		new_mat.set_shader_parameter("_AlphaCutoutEnable", 1.0)

	// 	if godot_shader_outline != null:
	// 		var outline_mat = new_mat.duplicate()
	// 		outline_mat.shader = godot_shader_outline

	// 		new_mat.next_pass = outline_mat

	// 	return new_mat

	void _update_materials(Dictionary vrm_extension, Ref<GLTFState> gstate) {
		// 	var images = gstate.get_images()
		// 	#print(images)
		// 	var materials : Array = gstate.get_materials();
		// 	var spatial_to_shader_mat : Dictionary = {}

		// 	# Render priority setup
		// 	var render_queue_to_priority: Array = []
		// 	var negative_render_queue_to_priority: Array = []
		// 	var uniq_render_queues: Dictionary = {}
		// 	negative_render_queue_to_priority.push_back(0)
		// 	render_queue_to_priority.push_back(0)
		// 	uniq_render_queues[0] = true
		// 	for i in range(materials.size()):
		// 		var oldmat: Material = materials[i]
		// 		var vrm_mat: Dictionary = vrm_extension["materialProperties"][i]
		// 		var delta_render_queue = vrm_mat.get("renderQueue", 3000) - 3000
		// 		if not uniq_render_queues.has(delta_render_queue):
		// 			uniq_render_queues[delta_render_queue] = true
		// 			if delta_render_queue < 0:
		// 				negative_render_queue_to_priority.push_back(-delta_render_queue)
		// 			else:
		// 				render_queue_to_priority.push_back(delta_render_queue)
		// 	negative_render_queue_to_priority.sort()
		// 	render_queue_to_priority.sort()

		// 	# Material conversions
		// 	for i in range(materials.size()):
		// 		var oldmat: Material = materials[i]
		// 		if (oldmat is ShaderMaterial):
		// 			# Indicates that the user asked to keep existing materials. Avoid changing them.
		// 			print("Material " + str(i) + ": " + str(oldmat.resource_name) + " already is shader.")
		// 			continue
		// 		var newmat: Material = _process_khr_material(oldmat, gstate.json["materials"][i])
		// 		var vrm_mat_props: Dictionary = vrm_extension["materialProperties"][i]
		// 		newmat = _process_vrm_material(newmat, images, vrm_mat_props)
		// 		spatial_to_shader_mat[oldmat] = newmat
		// 		spatial_to_shader_mat[newmat] = newmat
		// 		# print("Replacing shader " + str(oldmat) + "/" + str(oldmat.resource_name) + " with " + str(newmat) + "/" + str(newmat.resource_name))
		// 		var target_render_priority = 0
		// 		var delta_render_queue = vrm_mat_props.get("renderQueue", 3000) - 3000
		// 		if delta_render_queue >= 0:
		// 			target_render_priority = render_queue_to_priority.find(delta_render_queue)
		// 			if target_render_priority > 100:
		// 				target_render_priority = 100
		// 		else:
		// 			target_render_priority = -negative_render_queue_to_priority.find(-delta_render_queue)
		// 			if target_render_priority < -100:
		// 				target_render_priority = -100
		// 		# render_priority only makes sense for transparent materials.
		// 		if newmat.get_class() == "StandardMaterial3D":
		// 			if int(newmat.transparency) > 0:
		// 				newmat.render_priority = target_render_priority
		// 		else:
		// 			var blend_mode = int(vrm_mat_props["floatProperties"].get("_BlendMode", 0))
		// 			if blend_mode == int(RenderMode.Transparent) or blend_mode == int(RenderMode.TransparentWithZWrite):
		// 				newmat.render_priority = target_render_priority
		// 		materials[i] = newmat
		// 		var oldpath = oldmat.resource_path
		// 		oldmat.resource_path = ""
		// 		newmat.take_over_path(oldpath)
		// 		ResourceSaver.save(newmat, oldpath)
		// 	gstate.set_materials(materials)

		// 	var meshes = gstate.get_meshes()
		// 	for i in range(meshes.size()):
		// 		var gltfmesh: GLTFMesh = meshes[i]
		// 		var mesh = gltfmesh.mesh
		// 		mesh.set_blend_shape_mode(Mesh.BLEND_SHAPE_MODE_NORMALIZED)
		// 		for surf_idx in range(mesh.get_surface_count()):
		// 			var surfmat = mesh.get_surface_material(surf_idx)
		// 			if spatial_to_shader_mat.has(surfmat):
		// 				mesh.set_surface_material(surf_idx, spatial_to_shader_mat[surfmat])
		// 			else:
		// 				printerr("Mesh " + str(i) + " material " + str(surf_idx) + " name " + str(surfmat.resource_name) + " has no replacement material.")
	}
	Skeleton3D *_get_skel_godot_node(Ref<GLTFState> gstate, TypedArray<GLTFNode> nodes, Array skeletons, GLTFSkeletonIndex skel_id) {
		// 	# There's no working direct way to convert from skeleton_id to node_id.
		// 	# Bugs:
		// 	# GLTFNode.parent is -1 if skeleton bone.
		// 	# skeleton_to_node is empty
		// 	# get_scene_node(skeleton bone) works though might maybe return an attachment.
		// 	# var skel_node_idx = nodes[gltfskel.roots[0]]
		// 	# return gstate.get_scene_node(skel_node_idx) # as Skeleton
		for (int32_t node_i = 0; node_i < nodes.size(); node_i++) {
			Ref<GLTFNode> gltf_node = cast_to<GLTFNode>(nodes[node_i]);
			if (gltf_node->get_skeleton() == skel_id) {
				return cast_to<Skeleton3D>(gstate->get_scene_node(node_i));
			}
		}
		return nullptr;
	}

	// class SkelBone:
	// 	var skel: Skeleton3D
	// 	var bone_name: String

	// # https://github.com/vrm-c/vrm-specification/blob/master/specification/0.0/schema/vrm.humanoid.bone.schema.json
	// # vrm_extension["humanoid"]["bone"]:
	// #"enum": ["hips","leftUpperLeg","rightUpperLeg","leftLowerLeg","rightLowerLeg","leftFoot","rightFoot",
	// # "spine","chest","neck","head","leftShoulder","rightShoulder","leftUpperArm","rightUpperArm",
	// # "leftLowerArm","rightLowerArm","leftHand","rightHand","leftToes","rightToes","leftEye","rightEye","jaw",
	// # "leftThumbProximal","leftThumbIntermediate","leftThumbDistal",
	// # "leftIndexProximal","leftIndexIntermediate","leftIndexDistal",
	// # "leftMiddleProximal","leftMiddleIntermediate","leftMiddleDistal",
	// # "leftRingProximal","leftRingIntermediate","leftRingDistal",
	// # "leftLittleProximal","leftLittleIntermediate","leftLittleDistal",
	// # "rightThumbProximal","rightThumbIntermediate","rightThumbDistal",
	// # "rightIndexProximal","rightIndexIntermediate","rightIndexDistal",
	// # "rightMiddleProximal","rightMiddleIntermediate","rightMiddleDistal",
	// # "rightRingProximal","rightRingIntermediate","rightRingDistal",
	// # "rightLittleProximal","rightLittleIntermediate","rightLittleDistal", "upperChest"]

	Ref<VRMMeta> _create_meta(Node *root_node, AnimationPlayer *animplayer, Dictionary vrm_extension, Ref<GLTFState> gstate, Skeleton3D *skeleton, Ref<BoneMap> humanBones, Dictionary human_bone_to_idx, TypedArray<Basis> pose_diffs) {
		// 	var nodes = gstate.get_nodes()

		// 	var skeletonPath: NodePath = root_node.get_path_to(skeleton)
		// 	root_node.set("vrm_skeleton", skeletonPath)

		// 	var animPath: NodePath = root_node.get_path_to(animplayer)
		// 	root_node.set("vrm_animplayer", animPath)

		// 	var firstperson = vrm_extension.get("firstPerson", null)
		// 	var eyeOffset: Vector3;

		// 	if firstperson:
		// 		# FIXME: Technically this is supposed to be offset relative to the "firstPersonBone"
		// 		# However, firstPersonBone defaults to Head...
		// 		# and the semantics of a VR player having their viewpoint out of something which does
		// 		# not rotate with their head is unclear.
		// 		# Additionally, the spec schema says this:
		// 		# "It is assumed that an offset from the head bone to the VR headset is added."
		// 		# Which implies that the Head bone is used, not the firstPersonBone.
		// 		var fpboneoffsetxyz = firstperson["firstPersonBoneOffset"] # example: 0,0.06,0
		// 		eyeOffset = Vector3(fpboneoffsetxyz["x"], fpboneoffsetxyz["y"], fpboneoffsetxyz["z"])
		// 		if human_bone_to_idx["head"] != -1:
		// 			eyeOffset = pose_diffs[human_bone_to_idx["head"]] * eyeOffset

		Ref<VRMMeta> vrm_meta;
		vrm_meta.instantiate();
		return vrm_meta;

		// 	vrm_meta.resource_name = "CLICK TO SEE METADATA"
		// 	vrm_meta.exporter_version = vrm_extension.get("exporterVersion", "")
		// 	vrm_meta.spec_version = vrm_extension.get("specVersion", "")
		// 	var vrm_extension_meta = vrm_extension.get("meta")
		// 	if vrm_extension_meta:
		// 		vrm_meta.title = vrm_extension["meta"].get("title", "")
		// 		vrm_meta.version = vrm_extension["meta"].get("version", "")
		// 		vrm_meta.author = vrm_extension["meta"].get("author", "")
		// 		vrm_meta.contact_information = vrm_extension["meta"].get("contactInformation", "")
		// 		vrm_meta.reference_information = vrm_extension["meta"].get("reference", "")
		// 		var tex: int = vrm_extension["meta"].get("texture", -1)
		// 		if tex >= 0:
		// 			var gltftex: GLTFTexture = gstate.get_textures()[tex]
		// 			vrm_meta.texture = gstate.get_images()[gltftex.src_image]
		// 		vrm_meta.allowed_user_name = vrm_extension["meta"].get("allowedUserName", "")
		// 		vrm_meta.violent_usage = vrm_extension["meta"].get("violentUssageName", "") # Ussage (sic.) in VRM spec
		// 		vrm_meta.sexual_usage = vrm_extension["meta"].get("sexualUssageName", "") # Ussage (sic.) in VRM spec
		// 		vrm_meta.commercial_usage = vrm_extension["meta"].get("commercialUssageName", "") # Ussage (sic.) in VRM spec
		// 		vrm_meta.other_permission_url = vrm_extension["meta"].get("otherPermissionUrl", "")
		// 		vrm_meta.license_name = vrm_extension["meta"].get("licenseName", "")
		// 		vrm_meta.other_license_url = vrm_extension["meta"].get("otherLicenseUrl", "")

		// 	vrm_meta.eye_offset = eyeOffset
		// 	vrm_meta.humanoid_bone_mapping = humanBones
		// 	vrm_meta.humanoid_skeleton_path = skeletonPath
		// 	return vrm_meta
	}

	AnimationPlayer *_create_animation_player(AnimationPlayer *animplayer, Dictionary vrm_extension, Ref<GLTFState> gstate, Dictionary human_bone_to_idx, TypedArray<Basis> pose_diffs) {
		return animplayer;
	}
	// 	# Remove all glTF animation players for safety.
	// 	# VRM does not support animation import in this way.
	// 	for i in range(gstate.get_animation_players_count(0)):
	// 		var node: AnimationPlayer = gstate.get_animation_player(i)
	// 		node.get_parent().remove_child(node)

	// 	var animation_library : AnimationLibrary = AnimationLibrary.new()

	// 	var meshes = gstate.get_meshes()
	// 	var nodes = gstate.get_nodes()
	// 	var blend_shape_groups = vrm_extension["blendShapeMaster"]["blendShapeGroups"]
	// 	# FIXME: Do we need to handle multiple references to the same mesh???
	// 	var mesh_idx_to_meshinstance : Dictionary = {}
	// 	var material_name_to_mesh_and_surface_idx: Dictionary = {}
	// 	for i in range(meshes.size()):
	// 		var gltfmesh : GLTFMesh = meshes[i]
	// 		for j in range(gltfmesh.mesh.get_surface_count()):
	// 			material_name_to_mesh_and_surface_idx[gltfmesh.mesh.get_surface_material(j).resource_name] = [i, j]

	// 	for i in range(nodes.size()):
	// 		var gltfnode: GLTFNode = nodes[i]
	// 		var mesh_idx: int = gltfnode.mesh
	// 		#print("node idx " + str(i) + " node name " + gltfnode.resource_name + " mesh idx " + str(mesh_idx))
	// 		if (mesh_idx != -1):
	// 			var scenenode: ImporterMeshInstance3D = gstate.get_scene_node(i)
	// 			mesh_idx_to_meshinstance[mesh_idx] = scenenode
	// 			#print("insert " + str(mesh_idx) + " node name " + scenenode.name)

	// 	for shape in blend_shape_groups:
	// 		#print("Blend shape group: " + shape["name"])
	// 		var anim = Animation.new()

	// 		for matbind in shape["materialValues"]:
	// 			var mesh_and_surface_idx = material_name_to_mesh_and_surface_idx[matbind["materialName"]]
	// 			var node: ImporterMeshInstance3D = mesh_idx_to_meshinstance[mesh_and_surface_idx[0]]
	// 			var surface_idx = mesh_and_surface_idx[1]

	// 			var mat: Material = node.get_surface_material(surface_idx)
	// 			var paramprop = "shader_uniform/" + matbind["parameterName"]
	// 			var origvalue = null
	// 			var tv = matbind["targetValue"]
	// 			var newvalue = tv[0]

	// 			if (mat is ShaderMaterial):
	// 				var smat: ShaderMaterial = mat
	// 				var param = smat.get_shader_uniform(matbind["parameterName"])
	// 				if param is Color:
	// 					origvalue = param
	// 					newvalue = Color(tv[0], tv[1], tv[2], tv[3])
	// 				elif matbind["parameterName"] == "_MainTex" or matbind["parameterName"] == "_MainTex_ST":
	// 					origvalue = param
	// 					newvalue = Plane(tv[2], tv[3], tv[0], tv[1]) if matbind["parameterName"] == "_MainTex" else Plane(tv[0], tv[1], tv[2], tv[3])
	// 				elif param is float:
	// 					origvalue = param
	// 					newvalue = tv[0]
	// 				else:
	// 					printerr("Unknown type for parameter " + matbind["parameterName"] + " surface " + node.name + "/" + str(surface_idx))

	// 			if origvalue != null:
	// 				var animtrack: int = anim.add_track(Animation.TYPE_VALUE)
	// 				anim.track_set_path(animtrack, str(animplayer.get_parent().get_path_to(node)) + ":mesh:surface_" + str(surface_idx) + "/material:" + paramprop)
	// 				anim.track_set_interpolation_type(animtrack, Animation.INTERPOLATION_NEAREST if bool(shape["isBinary"]) else Animation.INTERPOLATION_LINEAR)
	// 				anim.track_insert_key(animtrack, 0.0, origvalue)
	// 				anim.track_insert_key(animtrack, 0.0, newvalue)
	// 		for bind in shape["binds"]:
	// 			# FIXME: Is this a mesh_idx or a node_idx???
	// 			var node: ImporterMeshInstance3D = mesh_idx_to_meshinstance[int(bind["mesh"])]
	// 			var nodeMesh: ImporterMesh = node.mesh;

	// 			if (bind["index"] < 0 || bind["index"] >= nodeMesh.get_blend_shape_count()):
	// 				printerr("Invalid blend shape index in bind " + str(shape) + " for mesh " + str(node.name))
	// 				continue
	// 			var animtrack: int = anim.add_track(Animation.TYPE_BLEND_SHAPE)
	// 			# nodeMesh.set_blend_shape_name(int(bind["index"]), shape["name"] + "_" + str(bind["index"]))
	// 			anim.track_set_path(animtrack, str(animplayer.get_parent().get_path_to(node)) + ":" + str(nodeMesh.get_blend_shape_name(int(bind["index"]))))
	// 			var interpolation: int = Animation.INTERPOLATION_LINEAR
	// 			if shape.has("isBinary") and bool(shape["isBinary"]):
	// 				interpolation = Animation.INTERPOLATION_NEAREST
	// 			anim.track_set_interpolation_type(animtrack, interpolation)
	// 			anim.track_insert_key(animtrack, 0.0, float(0.0))
	// 			# FIXME: Godot has weird normal/tangent singularities at weight=1.0 or weight=0.5
	// 			# So we multiply by 0.99999 to produce roughly the same output, avoiding these singularities.
	// 			anim.track_insert_key(animtrack, 1.0, 0.99999 * float(bind["weight"]) / 100.0)
	// 			#var mesh:ArrayMesh = meshes[bind["mesh"]].mesh
	// 			#print("Mesh name: " + mesh.resource_name)
	// 			#print("Bind index: " + str(bind["index"]))
	// 			#print("Bind weight: " + str(float(bind["weight"]) / 100.0))

	// 		# https://github.com/vrm-c/vrm-specification/tree/master/specification/0.0#blendshape-name-identifier
	// 		animation_library.add_animation(shape["name"].to_upper() if shape["presetName"] == "unknown" else shape["presetName"].to_upper(), anim)

	// 	var firstperson = vrm_extension["firstPerson"]

	// 	var firstpersanim: Animation = Animation.new()
	// 	animation_library.add_animation("FirstPerson", firstpersanim)

	// 	var thirdpersanim: Animation = Animation.new()
	// 	animation_library.add_animation("ThirdPerson", thirdpersanim)

	// 	var skeletons:Array = gstate.get_skeletons()

	// 	var head_bone_idx = firstperson.get("firstPersonBone", -1)
	// 	if (head_bone_idx >= 0):
	// 		var headNode: GLTFNode = nodes[head_bone_idx]
	// 		var skeletonPath:NodePath = animplayer.get_parent().get_path_to(_get_skel_godot_node(gstate, nodes, skeletons, headNode.skeleton))
	// 		var headBone: String = headNode.resource_name
	// 		var headPath = str(skeletonPath) + ":" + headBone
	// 		var firstperstrack = firstpersanim.add_track(Animation.TYPE_SCALE_3D)
	// 		firstpersanim.track_set_path(firstperstrack, headPath)
	// 		firstpersanim.scale_track_insert_key(firstperstrack, 0.0, Vector3(0.00001, 0.00001, 0.00001))
	// 		var thirdperstrack = thirdpersanim.add_track(Animation.TYPE_SCALE_3D)
	// 		thirdpersanim.track_set_path(thirdperstrack, headPath)
	// 		thirdpersanim.scale_track_insert_key(thirdperstrack, 0.0, Vector3.ONE)

	// 	for meshannotation in firstperson["meshAnnotations"]:

	// 		var flag = FirstPersonParser.get(meshannotation["firstPersonFlag"], -1)
	// 		var first_person_visibility;
	// 		var third_person_visibility;
	// 		if flag == FirstPersonFlag.ThirdPersonOnly:
	// 			first_person_visibility = 0.0
	// 			third_person_visibility = 1.0
	// 		elif flag == FirstPersonFlag.FirstPersonOnly:
	// 			first_person_visibility = 1.0
	// 			third_person_visibility = 0.0
	// 		else:
	// 			continue
	// 		var node: ImporterMeshInstance3D = mesh_idx_to_meshinstance[int(meshannotation["mesh"])]
	// 		var firstperstrack = firstpersanim.add_track(Animation.TYPE_VALUE)
	// 		firstpersanim.track_set_path(firstperstrack, str(animplayer.get_parent().get_path_to(node)) + ":visible")
	// 		firstpersanim.track_insert_key(firstperstrack, 0.0, first_person_visibility)
	// 		var thirdperstrack = thirdpersanim.add_track(Animation.TYPE_VALUE)
	// 		thirdpersanim.track_set_path(thirdperstrack, str(animplayer.get_parent().get_path_to(node)) + ":visible")
	// 		thirdpersanim.track_insert_key(thirdperstrack, 0.0, third_person_visibility)

	// 	if firstperson.get("lookAtTypeName", "") == "Bone":
	// 		var horizout = firstperson["lookAtHorizontalOuter"]
	// 		var horizin = firstperson["lookAtHorizontalInner"]
	// 		var vertup = firstperson["lookAtVerticalUp"]
	// 		var vertdown = firstperson["lookAtVerticalDown"]
	// 		var lefteye: int = human_bone_to_idx.get("leftEye", -1)
	// 		var righteye: int = human_bone_to_idx.get("rightEye", -1)
	// 		var leftEyePath:String = ""
	// 		var rightEyePath:String = ""
	// 		if lefteye > 0:
	// 			var leftEyeNode: GLTFNode = nodes[lefteye]
	// 			var skeleton:Skeleton3D = _get_skel_godot_node(gstate, nodes, skeletons,leftEyeNode.skeleton)
	// 			var skeletonPath:NodePath = animplayer.get_parent().get_path_to(skeleton)
	// 			leftEyePath = str(skeletonPath) + ":" + nodes[human_bone_to_idx["leftEye"]].resource_name
	// 		if righteye > 0:
	// 			var rightEyeNode: GLTFNode = nodes[righteye]
	// 			var skeleton:Skeleton3D = _get_skel_godot_node(gstate, nodes, skeletons,rightEyeNode.skeleton)
	// 			var skeletonPath:NodePath = animplayer.get_parent().get_path_to(skeleton)
	// 			rightEyePath = str(skeletonPath) + ":" + nodes[human_bone_to_idx["rightEye"]].resource_name

	// 		var anim: Animation = null
	// 		if not animplayer.has_animation("LOOKLEFT"):
	// 			anim = Animation.new()
	// 			animation_library.add_animation("LOOKLEFT", anim)
	// 		anim = animplayer.get_animation("LOOKLEFT")
	// 		if anim and lefteye > 0 and righteye > 0:
	// 			var animtrack: int = anim.add_track(Animation.TYPE_ROTATION_3D)
	// 			anim.track_set_path(animtrack, leftEyePath)
	// 			anim.track_set_interpolation_type(animtrack, Animation.INTERPOLATION_LINEAR)
	// 			anim.rotation_track_insert_key(animtrack, 0.0, Quaternion.IDENTITY)
	// 			anim.rotation_track_insert_key(animtrack, horizout["xRange"] / 90.0, (pose_diffs[lefteye] * Basis(Vector3(0,1,0), horizout["yRange"] * 3.14159/180.0)).get_rotation_quaternion())
	// 			animtrack = anim.add_track(Animation.TYPE_ROTATION_3D)
	// 			anim.track_set_path(animtrack, rightEyePath)
	// 			anim.track_set_interpolation_type(animtrack, Animation.INTERPOLATION_LINEAR)
	// 			anim.rotation_track_insert_key(animtrack, 0.0, Quaternion.IDENTITY)
	// 			anim.rotation_track_insert_key(animtrack, horizin["xRange"] / 90.0, (pose_diffs[righteye] * Basis(Vector3(0,1,0), horizin["yRange"] * 3.14159/180.0)).get_rotation_quaternion())

	// 		if not animplayer.has_animation("LOOKRIGHT"):
	// 			anim = Animation.new()
	// 			animation_library.add_animation("LOOKRIGHT", anim)
	// 		anim = animplayer.get_animation("LOOKRIGHT")
	// 		if anim and lefteye > 0 and righteye > 0:
	// 			var animtrack: int = anim.add_track(Animation.TYPE_ROTATION_3D)
	// 			anim.track_set_path(animtrack, leftEyePath)
	// 			anim.track_set_interpolation_type(animtrack, Animation.INTERPOLATION_LINEAR)
	// 			anim.rotation_track_insert_key(animtrack, 0.0, Quaternion.IDENTITY)
	// 			anim.rotation_track_insert_key(animtrack, horizin["xRange"] / 90.0, (pose_diffs[lefteye] * Basis(Vector3(0,1,0), -horizin["yRange"] * 3.14159/180.0)).get_rotation_quaternion())
	// 			animtrack = anim.add_track(Animation.TYPE_ROTATION_3D)
	// 			anim.track_set_path(animtrack, rightEyePath)
	// 			anim.track_set_interpolation_type(animtrack, Animation.INTERPOLATION_LINEAR)
	// 			anim.rotation_track_insert_key(animtrack, 0.0, Quaternion.IDENTITY)
	// 			anim.rotation_track_insert_key(animtrack, horizout["xRange"] / 90.0, (pose_diffs[righteye] * Basis(Vector3(0,1,0), -horizout["yRange"] * 3.14159/180.0)).get_rotation_quaternion())

	// 		if not animplayer.has_animation("LOOKUP"):
	// 			anim = Animation.new()
	// 			animation_library.add_animation("LOOKUP", anim)
	// 		anim = animplayer.get_animation("LOOKUP")
	// 		if anim and lefteye > 0 and righteye > 0:
	// 			var animtrack: int = anim.add_track(Animation.TYPE_ROTATION_3D)
	// 			anim.track_set_path(animtrack, leftEyePath)
	// 			anim.track_set_interpolation_type(animtrack, Animation.INTERPOLATION_LINEAR)
	// 			anim.rotation_track_insert_key(animtrack, 0.0, Quaternion.IDENTITY)
	// 			anim.rotation_track_insert_key(animtrack, vertup["xRange"] / 90.0, (pose_diffs[lefteye] * Basis(Vector3(1,0,0), vertup["yRange"] * 3.14159/180.0)).get_rotation_quaternion())
	// 			animtrack = anim.add_track(Animation.TYPE_ROTATION_3D)
	// 			anim.track_set_path(animtrack, rightEyePath)
	// 			anim.track_set_interpolation_type(animtrack, Animation.INTERPOLATION_LINEAR)
	// 			anim.rotation_track_insert_key(animtrack, 0.0, Quaternion.IDENTITY)
	// 			anim.rotation_track_insert_key(animtrack, vertup["xRange"] / 90.0, (pose_diffs[righteye] * Basis(Vector3(1,0,0), vertup["yRange"] * 3.14159/180.0)).get_rotation_quaternion())

	// 		if not animplayer.has_animation("LOOKDOWN"):
	// 			anim = Animation.new()
	// 			animation_library.add_animation("LOOKDOWN", anim)
	// 		anim = animplayer.get_animation("LOOKDOWN")
	// 		if anim and lefteye > 0 and righteye > 0:
	// 			var animtrack: int = anim.add_track(Animation.TYPE_ROTATION_3D)
	// 			anim.track_set_path(animtrack, leftEyePath)
	// 			anim.track_set_interpolation_type(animtrack, Animation.INTERPOLATION_LINEAR)
	// 			anim.rotation_track_insert_key(animtrack, 0.0, Quaternion.IDENTITY)
	// 			anim.rotation_track_insert_key(animtrack, vertdown["xRange"] / 90.0, (pose_diffs[lefteye] * Basis(Vector3(1,0,0), -vertdown["yRange"] * 3.14159/180.0)).get_rotation_quaternion())
	// 			animtrack = anim.add_track(Animation.TYPE_ROTATION_3D)
	// 			anim.track_set_path(animtrack, rightEyePath)
	// 			anim.track_set_interpolation_type(animtrack, Animation.INTERPOLATION_LINEAR)
	// 			anim.rotation_track_insert_key(animtrack, 0.0, Quaternion.IDENTITY)
	// 			anim.rotation_track_insert_key(animtrack, vertdown["xRange"] / 90.0, (pose_diffs[righteye] * Basis(Vector3(1,0,0), -vertdown["yRange"] * 3.14159/180.0)).get_rotation_quaternion())
	// 	animplayer.add_animation_library("vrm", animation_library)
	// 	return animplayer

	void _parse_secondary_node(Node *secondary_node, Dictionary vrm_extension, Ref<GLTFState> gstate, TypedArray<Basis> pose_diffs, bool is_vrm_0) {
		// 	var nodes = gstate.get_nodes()
		// 	var skeletons = gstate.get_skeletons()

		// 	var offset_flip: Vector3 = Vector3(-1,1,-1) if is_vrm_0 else Vector3(1,1,1)

		// 	var collider_groups: Array = [].duplicate()
		// 	for cgroup in vrm_extension["secondaryAnimation"]["colliderGroups"]:
		// 		var gltfnode: GLTFNode = nodes[int(cgroup["node"])]
		// 		var collider_group = vrm_collidergroup.new()
		// 		collider_group.sphere_colliders = [].duplicate() # HACK HACK HACK
		// 		var pose_diff: Basis = Basis()
		// 		if gltfnode.skeleton == -1:
		// 			var found_node: Node = gstate.get_scene_node(int(cgroup["node"]))
		// 			collider_group.skeleton_or_node = secondary_node.get_path_to(found_node)
		// 			collider_group.bone = ""
		// 			collider_group.resource_name = found_node.name
		// 		else:
		// 			var skeleton: Skeleton3D = _get_skel_godot_node(gstate, nodes, skeletons,gltfnode.skeleton)
		// 			collider_group.skeleton_or_node = secondary_node.get_path_to(skeleton)
		// 			collider_group.bone = nodes[int(cgroup["node"])].resource_name
		// 			collider_group.resource_name = collider_group.bone
		// 			pose_diff = pose_diffs[skeleton.find_bone(collider_group.bone)]

		// 		for collider_info in cgroup["colliders"]:
		// 			var offset_obj = collider_info.get("offset", {"x": 0.0, "y": 0.0, "z": 0.0})
		// 			var local_pos: Vector3 = pose_diff * offset_flip * Vector3(offset_obj["x"], offset_obj["y"], offset_obj["z"])
		// 			var radius: float = collider_info.get("radius", 0.0)
		// 			collider_group.sphere_colliders.append(Plane(local_pos, radius))
		// 		collider_groups.append(collider_group)

		// 	var spring_bones: Array = [].duplicate()
		// 	for sbone in vrm_extension["secondaryAnimation"]["boneGroups"]:
		// 		if sbone.get("bones", []).size() == 0:
		// 			continue
		// 		var first_bone_node: int = sbone["bones"][0]
		// 		var gltfnode: GLTFNode = nodes[int(first_bone_node)]
		// 		var skeleton: Skeleton3D = _get_skel_godot_node(gstate, nodes, skeletons,gltfnode.skeleton)

		// 		var spring_bone = VRMSpringBone.new()
		// 		spring_bone.skeleton = secondary_node.get_path_to(skeleton)
		// 		spring_bone.comment = sbone.get("comment", "")
		// 		spring_bone.stiffness_force = float(sbone.get("stiffiness", 1.0))
		// 		spring_bone.gravity_power = float(sbone.get("gravityPower", 0.0))
		// 		var gravity_dir = sbone.get("gravity_dir", {"x": 0.0, "y": -1.0, "z": 0.0})
		// 		spring_bone.gravity_dir = Vector3(gravity_dir["x"], gravity_dir["y"], gravity_dir["z"])
		// 		spring_bone.drag_force = float(sbone.get("drag_force", 0.4))
		// 		spring_bone.hit_radius = float(sbone.get("hitRadius", 0.02))

		// 		if spring_bone.comment != "":
		// 			spring_bone.resource_name = spring_bone.comment.split("\n")[0]
		// 		else:
		// 			var tmpname: String = ""
		// 			if sbone["bones"].size() > 1:
		// 				tmpname += " + " + str(sbone["bones"].size() - 1) + " roots"
		// 			tmpname = nodes[int(first_bone_node)].resource_name + tmpname
		// 			spring_bone.resource_name = tmpname

		// 		spring_bone.collider_groups = [].duplicate() # HACK HACK HACK
		// 		for cgroup_idx in sbone.get("colliderGroups", []):
		// 			spring_bone.collider_groups.append(collider_groups[int(cgroup_idx)])

		// 		spring_bone.root_bones = [].duplicate() # HACK HACK HACK
		// 		for bone_node in sbone["bones"]:
		// 			var bone_name:String = nodes[int(bone_node)].resource_name
		// 			if skeleton.find_bone(bone_name) == -1:
		// 				# Note that we make an assumption that a given SpringBone object is
		// 				# only part of a single Skeleton*. This error might print if a given
		// 				# SpringBone references bones from multiple Skeleton's.
		// 				printerr("Failed to find node " + str(bone_node) + " in skel " + str(skeleton))
		// 			else:
		// 				spring_bone.root_bones.append(bone_name)

		// 		# Center commonly points outside of the glTF Skeleton, such as the root node.
		// 		spring_bone.center_node = secondary_node.get_path_to(secondary_node)
		// 		spring_bone.center_bone = ""
		// 		var center_node_idx = sbone.get("center", -1)
		// 		if center_node_idx != -1:
		// 			var center_gltfnode: GLTFNode = nodes[int(center_node_idx)]
		// 			var bone_name:String = center_gltfnode.resource_name
		// 			if center_gltfnode.skeleton == gltfnode.skeleton and skeleton.find_bone(bone_name) != -1:
		// 				spring_bone.center_bone = bone_name
		// 				spring_bone.center_node = NodePath()
		// 			else:
		// 				spring_bone.center_bone = ""
		// 				spring_bone.center_node = secondary_node.get_path_to(gstate.get_scene_node(int(center_node_idx)))
		// 				if spring_bone.center_node == NodePath():
		// 					printerr("Failed to find center scene node " + str(center_node_idx))
		// 					spring_bone.center_node = secondary_node.get_path_to(secondary_node) # Fallback

		// 		spring_bones.append(spring_bone)

		// 	secondary_node.set_script(vrm_secondary)
		// 	secondary_node.set("spring_bones", spring_bones)
		// 	secondary_node.set("collider_groups", collider_groups)
	}
	// func _add_joints_recursive(new_joints_set: Dictionary, gltf_nodes: Array, bone: int, include_child_meshes: bool=false) -> void:
	// 	if bone < 0:
	// 		return
	// 	var gltf_node: Dictionary = gltf_nodes[bone]
	// 	if not include_child_meshes and gltf_node.get("mesh", -1) != -1:
	// 		return
	// 	new_joints_set[bone] = true
	// 	for child_node in gltf_node.get("children", []):
	// 		if not new_joints_set.has(child_node):
	// 			_add_joints_recursive(new_joints_set, gltf_nodes, int(child_node))

	// func _add_joint_set_as_skin(obj: Dictionary, new_joints_set: Dictionary) -> void:
	// 	var new_joints = [].duplicate()
	// 	for node in new_joints_set:
	// 		new_joints.push_back(node)
	// 	new_joints.sort()

	// 	var new_skin: Dictionary = {"joints": new_joints}

	// 	if not obj.has("skins"):
	// 		obj["skins"] = [].duplicate()

	// 	obj["skins"].push_back(new_skin)

	bool _add_vrm_nodes_to_skin(Dictionary obj) {
		// 	var vrm_extension: Dictionary = obj.get("extensions", {}).get("VRM", {})
		// 	if not vrm_extension.has("humanoid"):
		// 		return false
		// 	var new_joints_set = {}.duplicate()

		// 	var secondaryAnimation = vrm_extension.get("secondaryAnimation", {})
		// 	for bone_group in secondaryAnimation.get("boneGroups", []):
		// 		for bone in bone_group["bones"]:
		// 			_add_joints_recursive(new_joints_set, obj["nodes"], int(bone), true)

		// 	for collider_group in secondaryAnimation.get("colliderGroups", []):
		// 		if int(collider_group["node"]) >= 0:
		// 			new_joints_set[int(collider_group["node"])] = true

		// 	var firstPerson = vrm_extension.get("firstPerson", {})
		// 	if firstPerson.get("firstPersonBone", -1) >= 0:
		// 		new_joints_set[int(firstPerson["firstPersonBone"])] = true

		// 	for human_bone in vrm_extension["humanoid"]["humanBones"]:
		// 		_add_joints_recursive(new_joints_set, obj["nodes"], int(human_bone["node"]), false)

		// 	_add_joint_set_as_skin(obj, new_joints_set)
		return true;
	}

	TypedArray<Basis> apply_retarget(Ref<GLTFState> gstate, Node *root_node, Skeleton3D *skeleton, Ref<BoneMap> bone_map) {
		NodePath skeletonPath = root_node->get_path_to(skeleton);
		skeleton_rename(gstate, root_node, skeleton, bone_map);
		TypedArray<Basis> poses = skeleton_rotate(root_node, skeleton, bone_map);
		apply_rotation(root_node, skeleton);
		return poses;
	}

	virtual Node *import_scene(const String &p_path, uint32_t p_flags, const HashMap<StringName, Variant> &p_options, int p_bake_fps, List<String> *r_missing_deps, Error *r_err = nullptr) {
		Ref<GLTFState> gstate;
		gstate.instantiate();
		Ref<GLTFDocument> gltf;
		gltf.instantiate();
		Error err = gltf->append_from_file(p_path, gstate, p_flags, p_bake_fps, p_path.get_base_dir());
		ERR_FAIL_COND_V(err != OK, nullptr);
		Dictionary gltf_json_parsed = gstate->get_json();
		if (!_add_vrm_nodes_to_skin(gltf_json_parsed)) {
			print_error("Failed to find required VRM keys in json");
			return nullptr;
		}
		Node *original_root_node = gltf->generate_scene(gstate, 30);
		VRMTopLevel *root_node = memnew(VRMTopLevel);
		original_root_node->replace_by(root_node, true);
		bool is_vrm_0 = true;
		Dictionary gltf_json = gstate->get_json();
		Dictionary extension = gltf_json["extensions"];
		Dictionary vrm_extension = extension["VRM"];
		Dictionary human_bone_to_idx;
		// Ignoring in ["humanoid"]: armStretch, legStretch, upperArmTwist
		// lowerArmTwist, upperLegTwist, lowerLegTwist, feetSpacing,
		// and hasTranslationDoF
		Dictionary humanoid = vrm_extension["humanoid"];
		Array human_bones = humanoid["humanBones"];
		for (int32_t human_bone_i = 0; human_bone_i < human_bones.size(); human_bone_i++) {
			Dictionary human_bone = human_bones[human_bone_i];
			String bone_name = human_bone["bone"];
			int32_t node_id = human_bone["node"];
			human_bone_to_idx[bone_name] = node_id;
			// properties:
			// Ignoring: useDefaultValues
			// Ignoring: min
			// Ignoring: max
			// Ignoring: center
			// Ingoring: axisLength
		}
		TypedArray<GLTFSkeleton> skeletons = gstate->get_skeletons();
		Ref<GLTFNode> hipsNode = gstate->get_nodes()[human_bone_to_idx["hips"]];
		ERR_FAIL_NULL_V_MSG(hipsNode, nullptr, "Cannot import VRM. There is no hip bone defined.");
		Skeleton3D *skeleton = _get_skel_godot_node(gstate, gstate->get_nodes(), skeletons, hipsNode->get_skeleton());
		Array gltfnodes = gstate->get_nodes();
		Ref<BoneMap> humanBones;
		humanBones.instantiate();
		humanBones->set_profile(memnew(SkeletonProfileHumanoid));
		vrm_constants_class vrmconst_inst = vrm_constants_class(is_vrm_0); //vrm 0.0
		for (int32_t human_bone_name_i = 0; human_bone_name_i < human_bone_to_idx.keys().size(); human_bone_name_i++) {
			String human_bone_name = human_bone_to_idx.keys()[human_bone_name_i];
			int human_bone_idx = human_bone_to_idx[human_bone_name];
			Ref<GLTFNode> gltf_node = gstate->get_nodes()[human_bone_idx];
			if (gltf_node.is_null()) {
				continue;
			}
			String gltf_node_name = gltf_node->get_name();
			if (!vrmconst_inst.vrm_to_human_bone.has(human_bone_name)) {
				continue;
			}
			String profile_name = vrmconst_inst.vrm_to_human_bone[human_bone_name];
			humanBones->set_skeleton_bone_name(profile_name, gltf_node_name);
		}
		if (is_vrm_0) {
			// VRM 0.0 has models facing backwards due to a spec error (flipped z instead of x).
			print_line("Pre-rotate the VRM 0.0 model.");
			rotate_scene_180(root_node);
			print_line("Post-rotate the VRM 0.0 model.");
		}
		bool do_retarget = true;
		TypedArray<Basis> pose_diffs;
		if (do_retarget) {
			pose_diffs = apply_retarget(gstate, root_node, skeleton, humanBones);
		} else {
			for (int32_t bone_i = 0; bone_i < skeleton->get_bone_count(); bone_i++) {
				pose_diffs.append(Basis());
			}
		}
		_update_materials(vrm_extension, gstate);
		AnimationPlayer *animplayer = memnew(AnimationPlayer);
		animplayer->set_name("anim");
		root_node->add_child(animplayer, true);
		animplayer->set_owner(root_node);
		_create_animation_player(animplayer, vrm_extension, gstate, human_bone_to_idx, pose_diffs);
		Ref<Resource> vrm_meta = _create_meta(root_node, animplayer, vrm_extension, gstate, skeleton, humanBones, human_bone_to_idx, pose_diffs);
		root_node->set("vrm_meta", vrm_meta);
		root_node->set("vrm_secondary", NodePath());
		if (!vrm_extension.has("secondaryAnimation")) {
			return root_node;
		}
		Array collider_groups = vrm_extension["secondaryAnimation"].get("colliderGroups");
		Array bone_groups = vrm_extension["secondaryAnimation"].get("boneGroups");
		if (!(collider_groups.size() > 0 || bone_groups.size() > 0)) {
			return root_node;
		}
		Node *secondary_node = root_node->get_node_or_null(NodePath("secondary"));
		if (secondary_node == nullptr) {
			secondary_node = memnew(Node3D);
			root_node->add_child(secondary_node, true);
			secondary_node->set_owner(root_node);
			secondary_node->set_name("secondary");
		}
		NodePath secondary_path = root_node->get_path_to(secondary_node);
		root_node->set("vrm_secondary", secondary_path);
		_parse_secondary_node(secondary_node, vrm_extension, gstate, pose_diffs, is_vrm_0);
		return root_node;
	}
	virtual void get_import_options(const String &p_path, List<ResourceImporter::ImportOption> *r_options) {}
	virtual Variant get_option_visibility(const String &p_path, bool p_for_animation, const String &p_option, const HashMap<StringName, Variant> &p_options) { return Variant(); }
};

class VRMEditorPlugin : public EditorPlugin {
	GDCLASS(VRMEditorPlugin, EditorPlugin);
	Ref<VRMEditorSceneFormatImporter> import_plugin;

public:
	virtual String get_name() const override { return "VRM"; }

public:
	VRMEditorPlugin() {
		import_plugin.instantiate();
		add_scene_format_importer_plugin(import_plugin);
	}
	~VRMEditorPlugin() {
		remove_scene_format_importer_plugin(import_plugin);
	}
};
// #endif

void initialize_vrm_module(ModuleInitializationLevel p_level);
void uninitialize_vrm_module(ModuleInitializationLevel p_level);