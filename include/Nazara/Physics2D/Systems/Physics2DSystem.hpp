// Copyright (C) 2023 Jérôme "Lynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Physics2D module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_PHYSICS2D_SYSTEMS_PHYSICS2DSYSTEM_HPP
#define NAZARA_PHYSICS2D_SYSTEMS_PHYSICS2DSYSTEM_HPP

#include <NazaraUtils/Prerequisites.hpp>
#include <Nazara/Core/Time.hpp>
#include <Nazara/Physics2D/PhysWorld2D.hpp>
#include <Nazara/Physics2D/Components/RigidBody2DComponent.hpp>
#include <NazaraUtils/TypeList.hpp>
#include <entt/entt.hpp>

namespace Nz
{
	class NAZARA_PHYSICS2D_API Physics2DSystem
	{
		public:
			static constexpr Int64 ExecutionOrder = 0;
			using Components = TypeList<RigidBody2DComponent, class NodeComponent>;

			Physics2DSystem(entt::registry& registry);
			Physics2DSystem(const Physics2DSystem&) = delete;
			Physics2DSystem(Physics2DSystem&&) = delete;
			~Physics2DSystem();

			template<typename... Args> RigidBody2DComponent CreateRigidBody(Args&&... args);

			inline PhysWorld2D& GetPhysWorld();
			inline const PhysWorld2D& GetPhysWorld() const;

			void Update(Time elapsedTime);

			Physics2DSystem& operator=(const Physics2DSystem&) = delete;
			Physics2DSystem& operator=(Physics2DSystem&&) = delete;

		private:
			entt::registry& m_registry;
			entt::observer m_physicsConstructObserver;
			entt::scoped_connection m_constructConnection;
			PhysWorld2D m_physWorld;
	};
}

#include <Nazara/Physics2D/Systems/Physics2DSystem.inl>

#endif // NAZARA_PHYSICS2D_SYSTEMS_PHYSICS2DSYSTEM_HPP
