// Copyright (C) 2023 Jérôme "Lynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Utility module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_UTILITY_TRIANGLEITERATOR_HPP
#define NAZARA_UTILITY_TRIANGLEITERATOR_HPP

#include <NazaraUtils/Prerequisites.hpp>
#include <Nazara/Utility/Enums.hpp>
#include <Nazara/Utility/IndexMapper.hpp>

namespace Nz
{
	class SubMesh;

	class NAZARA_UTILITY_API TriangleIterator
	{
		public:
			TriangleIterator(PrimitiveMode primitiveMode, IndexBuffer& indexBuffer);
			TriangleIterator(SubMesh& subMesh);
			~TriangleIterator() = default;

			bool Advance();

			UInt32 operator[](std::size_t i) const;

			void Unmap();

		private:
			PrimitiveMode m_primitiveMode;
			UInt32 m_triangleIndices[3];
			IndexMapper m_indexMapper;
			std::size_t m_currentIndex;
			std::size_t m_indexCount;
	};
}

#endif // NAZARA_UTILITY_TRIANGLEITERATOR_HPP
