// Copyright (C) 2023 Jérôme "Lynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Renderer module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_RENDERER_SWAPCHAINPARAMETERS_HPP
#define NAZARA_RENDERER_SWAPCHAINPARAMETERS_HPP

#include <NazaraUtils/Prerequisites.hpp>
#include <Nazara/Utility/PixelFormat.hpp>
#include <vector>

namespace Nz
{
	struct SwapchainParameters
	{
		std::vector<PixelFormat> depthFormats = {Nz::PixelFormat::Depth24Stencil8, Nz::PixelFormat::Depth32FStencil8, Nz::PixelFormat::Depth16Stencil8, Nz::PixelFormat::Depth32F, Nz::PixelFormat::Depth24}; //< By order of preference
		bool verticalSync = false;
	};
}

#endif // NAZARA_RENDERER_SWAPCHAINPARAMETERS_HPP
