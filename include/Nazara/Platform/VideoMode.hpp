// Copyright (C) 2023 Jérôme "Lynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Platform module"
// For conditions of distribution and use, see copyright notice in Config.hpp

// Interface inspirée de la SFML par Laurent Gomila

#pragma once

#ifndef NAZARA_PLATFORM_VIDEOMODE_HPP
#define NAZARA_PLATFORM_VIDEOMODE_HPP

#include <NazaraUtils/Prerequisites.hpp>
#include <Nazara/Platform/Config.hpp>
#include <vector>

namespace Nz
{
	class NAZARA_PLATFORM_API VideoMode
	{
		public:
			VideoMode();
			VideoMode(unsigned int w, unsigned int h);
			VideoMode(unsigned int w, unsigned int h, UInt8 bpp);

			bool IsFullscreenValid() const;

			UInt8 bitsPerPixel;
			unsigned int height;
			unsigned int width;

			static VideoMode GetDesktopMode();
			static const std::vector<VideoMode>& GetFullscreenModes();
	};

	bool NAZARA_PLATFORM_API operator==(const VideoMode& left, const VideoMode& right);
	bool NAZARA_PLATFORM_API operator!=(const VideoMode& left, const VideoMode& right);
	bool NAZARA_PLATFORM_API operator<(const VideoMode& left, const VideoMode& right);
	bool NAZARA_PLATFORM_API operator<=(const VideoMode& left, const VideoMode& right);
	bool NAZARA_PLATFORM_API operator>(const VideoMode& left, const VideoMode& right);
	bool NAZARA_PLATFORM_API operator>=(const VideoMode& left, const VideoMode& right);
}

#endif // NAZARA_PLATFORM_VIDEOMODE_HPP
