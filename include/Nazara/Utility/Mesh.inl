// Copyright (C) 2023 Jérôme "Lynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Utility module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/Utility/StaticMesh.hpp>
#include <memory>
#include <Nazara/Utility/Debug.hpp>

namespace Nz
{
	inline Mesh::Mesh() :
	m_materialData(1),
	m_aabbUpdated(false),
	m_isValid(false)
	{
	}

	inline std::shared_ptr<Mesh> Mesh::Build(std::shared_ptr<StaticMesh> staticMesh)
	{
		std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		mesh->CreateStatic();
		mesh->AddSubMesh(std::move(staticMesh));

		return mesh;
	}

	inline std::shared_ptr<Mesh> Build(const Primitive& primitive, const MeshParams& params)
	{
		std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		mesh->CreateStatic();
		mesh->BuildSubMesh(primitive, params);

		return mesh;
	}

	inline std::shared_ptr<Mesh> Build(const PrimitiveList& primitiveList, const MeshParams& params)
	{
		std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		mesh->CreateStatic();
		mesh->BuildSubMeshes(primitiveList, params);

		return mesh;
	}
}

#include <Nazara/Utility/DebugOff.hpp>
