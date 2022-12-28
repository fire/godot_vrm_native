/*************************************************************************/
/*  register_types.h                                                     */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
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

#include "editor/editor_node.h"

#include "editor/import/resource_importer_scene.h"
#include "modules/gltf/extensions/gltf_document_extension.h"
#include "modules/gltf/gltf_document.h"
#include "modules/gltf/gltf_state.h"
#include "scene/resources/bone_map.h"
#include "scene/resources/immediate_mesh.h"

#include "register_types.h"

class VRMConstants : public RefCounted {
	GDCLASS(VRMConstants, RefCounted);

public:
	Dictionary vrm_to_human_bone;

	VRMConstants(bool is_vrm_0);
};

class VRMMeta : public Resource {
	GDCLASS(VRMMeta, Resource);

protected:
	static void _bind_methods();

public:
	// VRM extension is for 3d humanoid avatars (and models) in VR applications.
	// Meta schema:

	// The title of the VRM model.
	String title;
	void set_title(String p_title) {
		title = p_title;
	}
	String get_title() const{
		return title;
	}

	// The version of the VRM model.
	String version;
	void set_version(String p_version) {
		version = p_version;
	}
	String get_version() const{
		return version;
	}

	// The author of VRM model
	String author;

	// The contact Information of the VRM model author
	String contact_information;

	// The reference of the VRM model.
	String reference_information;

	// The thumbnail of the VRM model
	Ref<Texture2D> texture;

	// An person who can perform with this avatar.
	String allowed_user_name;
	// (String,"","OnlyAuthor","ExplicitlyLicensedPerson","Everyone")

	// A permission to perform violent acts with this avatar.
	String violent_usage;
	
	// (String,"","Disallow","Allow")
	// A permission to perform sexual acts with this avatar.
	String sexual_usage;
	// (String,"","Disallow","Allow")
	
	// For commercial use.
	String commercial_usage;
	// (String,"","Disallow","Allow")

	// If there are any conditions not mentioned above, put the URL link of the license document here.
	String other_permission_url;

	// The license type.
	String license_name;
	// (String,"","Redistribution_Prohibited","CC0","CC_BY","CC_BY_NC","CC_BY_SA","CC_BY_NC_SA","CC_BY_ND","CC_BY_NC_ND","Other")
	
	// If "Other" is selected, put the URL link of the license document here.
	String other_license_url;

	// Human bone name -> Reference node index
	
	// NOTE: We are currently discarding all Unity-specific data.
	// We may need to store it somewhere in case we wish to re-export.
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

class VRMTopLevel : public Node3D {
	GDCLASS(VRMTopLevel, Node3D);
	NodePath vrm_skeleton;
	NodePath vrm_animplayer;
	NodePath vrm_secondary;
	Ref<VRMMeta> vrm_meta;
	bool update_secondary_fixed = false;
	bool update_in_editor = false;
	bool gizmo_spring_bone = false;
	Color gizmo_spring_bone_color = Color(1, 1, 0.878431, 1);

public:
	NodePath get_vrm_skeleton();
	void set_vrm_skeleton(NodePath p_path);
	NodePath get_vrm_animplayer();
	void set_vrm_animplayer(NodePath p_path);
	NodePath get_vrm_secondary();
	void set_vrm_secondary(NodePath p_path);
	Ref<VRMMeta> get_vrm_meta();
	void set_vrm_meta(Ref<VRMMeta> p_meta);
	bool get_update_secondary_fixed();
	void set_update_secondary_fixed(bool p_fixed);
	bool get_update_in_editor();
	void set_update_in_editor(bool p_update);
	bool get_gizmo_spring_bone();
	void set_gizmo_spring_bone(bool p_update);
	Color get_gizmo_spring_bone_color();

protected:
	static void _bind_methods();

public:
	void set_gizmo_spring_bone_color(Color p_color);
	static Quaternion from_to_rotation(Vector3 from, Vector3 to);

	static Vector3 transform_point(Transform3D transform, Vector3 point);
	static Vector3 inv_transform_point(Transform3D transform, Vector3 point);
};

class SphereCollider : public Resource {
	GDCLASS(SphereCollider, Resource);

	friend class VRMEditorSceneFormatImporter;

public:
	int idx = -1;
	Vector3 offset;
	float radius = 0.0f;
	Vector3 position;

	void _ready(int bone_idx, Vector3 collider_offset = Vector3(), float collider_radius = 0.1f);
	void update(Node3D *parent, Skeleton3D *skel);
	float get_radius();
	Vector3 get_position();
};

// Individual spring bone entries.
class VRMSpringBoneLogic : public RefCounted {
	GDCLASS(VRMSpringBoneLogic, RefCounted);

	friend class VRMSecondary;

public:
	bool force_update = true;
	int bone_idx = -1;

	float radius = 0;
	float length = 0;

	Vector3 bone_axis;
	Vector3 current_tail;
	Vector3 prev_tail;

	Transform3D initial_transform;

	Transform3D get_transform(Skeleton3D *skel);
	Quaternion get_rotation(Skeleton3D *skel);

	Transform3D get_local_transform(Skeleton3D *skel);
	Quaternion get_local_rotation(Skeleton3D *skel);

	void reset(Skeleton3D *skel);

	void setup(Skeleton3D *skel, int idx, Variant center, Vector3 local_child_position, Transform3D default_pose);

	void update(Skeleton3D *skel, Variant center, float stiffness_force, float drag_force, Vector3 external, Vector<Ref<SphereCollider>> colliders);

	Vector3 collision(Skeleton3D *skel, Vector<Ref<SphereCollider>> colliders, Vector3 next_tail);
};

class VRMColliderGroup : public Resource {
	GDCLASS(VRMColliderGroup, Resource);

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

	void setup();
	void _ready(Node3D *ready_parent, Skeleton3D *ready_skel);
	void _process();
};

class VRMSpringBone : public Resource {
	GDCLASS(VRMSpringBone, Resource);

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

	void setup(bool force = false);

	void setup_recursive(int id, Variant center_tr);

	// Called when the node enters the scene tree for the first time.
	// TODO: Avoid shadowing godot methods.
	void _ready(Skeleton3D *ready_skel, Vector<Ref<SphereCollider>> colliders_ref);

	// Called every frame. 'delta' is the elapsed time since the previous frame.
	// TODO: Don't shadow godot methods.
	void _process(double delta);
};

class SecondaryGizmo;
class VRMSecondary : public Node3D {
	GDCLASS(VRMSecondary, Node3D);
	friend class SecondaryGizmo;

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
	void _notification(int p_what);

public:
	bool check_for_editor_update();
};

class SecondaryGizmo : public MeshInstance3D {
	GDCLASS(SecondaryGizmo, MeshInstance3D);

	VRMSecondary *secondary_node = nullptr;
	Ref<StandardMaterial3D> m = memnew(StandardMaterial3D);

public:
	SecondaryGizmo(Node *p_parent);

	void draw_spring_bones(Color color);

	void draw_collider_groups();

	void draw_line(Vector3 begin_pos, Vector3 end_pos, Color color);

	void draw_sphere(Basis bas, Vector3 center, float radius, Color color);
	void draw_in_editor(bool p_do_draw_spring_bones = false);

	void draw_in_game();
};

class VRMEditorSceneFormatImporter : public EditorSceneFormatImporter {
	GDCLASS(VRMEditorSceneFormatImporter, EditorSceneFormatImporter);

public:
	virtual uint32_t get_import_flags() const { return IMPORT_SCENE; }
	virtual void get_extensions(List<String> *r_extensions) const {
		r_extensions->push_back("vrm");
	}

public:
	Ref<Resource> vrm_met;
	const Basis ROTATE_180_BASIS = Basis(Vector3(-1, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, -1));
	const Transform3D ROTATE_180_TRANSFORM = Transform3D(ROTATE_180_BASIS, Vector3());

	void adjust_mesh_zforward(Ref<ImporterMesh> mesh);
	void skeleton_rename(Ref<GLTFState> gstate, Node *p_base_scene, Skeleton3D *p_skeleton, Ref<BoneMap> p_bone_map);

	void rotate_scene_180_inner(Node3D *p_node, Dictionary &mesh_set, Dictionary &skin_set);

	void rotate_scene_180(Node3D *p_scene);

	TypedArray<Basis> skeleton_rotate(Node *p_base_scene, Skeleton3D *src_skeleton, Ref<BoneMap> p_bone_map);

	void apply_rotation(Node *p_base_scene, Skeleton3D *src_skeleton);

	enum DebugMode {
		None = 0,
		Normal = 1,
		LitShadeRate = 2,
	};

	enum OutlineColorMode {
		FixedColor = 0,
		MixedLight3Ding = 1,
	};

	enum OutlineWidthMode {
		// None = 0,
		WorldCoordinates = 1,
		ScreenCoordinates = 2,
	};

	enum RenderMode {
		Opaque = 0,
		Cutout = 1,
		Transparent = 2,
		TransparentWithZWrite = 3,
	};

	enum CullMode {
		Off = 0,
		Front = 1,
		Back = 2,
	};

	enum FirstPersonFlag {
		Auto, // Create headlessModel
		Both, // Default layer
		ThirdPersonOnly,
		FirstPersonOnly,
	};

	Dictionary FirstPersonParser;

	VRMEditorSceneFormatImporter();

	Ref<Material> _process_khr_material(Ref<StandardMaterial3D> orig_mat, Dictionary gltf_mat_props);

	Dictionary _vrm_get_texture_info(Array gltf_images, Dictionary vrm_mat_props, String tex_name);

	float _vrm_get_float(Dictionary vrm_mat_props, String key, float def);

	Ref<Material> _process_vrm_material(Ref<StandardMaterial3D> orig_mat, Array gltf_images, Dictionary vrm_mat_props);

	void _update_materials(Dictionary vrm_extension, Ref<GLTFState> gstate);
	Skeleton3D *_get_skel_godot_node(Ref<GLTFState> gstate, TypedArray<GLTFNode> nodes, Array skeletons, GLTFSkeletonIndex skel_id);

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

	Ref<VRMMeta> _create_meta(Node *root_node, AnimationPlayer *animplayer, Dictionary vrm_extension, Ref<GLTFState> gstate, Skeleton3D *skeleton, Ref<BoneMap> humanBones, Dictionary human_bone_to_idx, TypedArray<Basis> pose_diffs);

	AnimationPlayer *_create_animation_player(AnimationPlayer *animplayer, Dictionary vrm_extension, Ref<GLTFState> gstate, Dictionary human_bone_to_idx, TypedArray<Basis> pose_diffs);

	void _parse_secondary_node(Node *secondary_node, Dictionary vrm_extension, Ref<GLTFState> gstate, TypedArray<Basis> pose_diffs, bool is_vrm_0);
	void _add_joints_recursive(Dictionary &new_joints_set, Array gltf_nodes, int bone, bool include_child_meshes = false);

	void _add_joint_set_as_skin(Dictionary &obj, Dictionary &new_joints_set);

	bool _add_vrm_nodes_to_skin(Dictionary &obj);

	TypedArray<Basis> apply_retarget(Ref<GLTFState> gstate, Node *root_node, Skeleton3D *skeleton, Ref<BoneMap> bone_map);

	virtual Node *import_scene(const String &p_path, uint32_t p_flags, const HashMap<StringName, Variant> &p_options, List<String> *r_missing_deps, Error *r_err = nullptr);
	virtual void get_import_options(const String &p_path, List<ResourceImporter::ImportOption> *r_options) {}
	virtual Variant get_option_visibility(const String &p_path, bool p_for_animation, const String &p_option, const HashMap<StringName, Variant> &p_options) { return Variant(); }
};

class VRMEditorPlugin : public EditorPlugin {
	GDCLASS(VRMEditorPlugin, EditorPlugin);
	Ref<VRMEditorSceneFormatImporter> import_plugin;

public:
	virtual String get_name() const override;

public:
	VRMEditorPlugin();
	~VRMEditorPlugin() {
		remove_scene_format_importer_plugin(import_plugin);
	}
};

void initialize_vrm_module(ModuleInitializationLevel p_level);
void uninitialize_vrm_module(ModuleInitializationLevel p_level);