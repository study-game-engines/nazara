// Copyright (C) 2023 Jérôme "Lynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Core module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_CORE_ENUMS_HPP
#define NAZARA_CORE_ENUMS_HPP

#include <NazaraUtils/Flags.hpp>

namespace Nz
{
	enum class CoordSys
	{
		Global,
		Local,

		Max = Local
	};

	enum class CursorPosition
	{
		AtBegin,   // beginning of the file
		AtCurrent, // Position of the cursor
		AtEnd,     // End of the file

		Max = AtEnd
	};

	enum class ErrorMode
	{
		None,

		Silent,
		SilentDisabled,
		ThrowException,
		ThrowExceptionDisabled,

		Max = ThrowExceptionDisabled
	};

	template<>
	struct EnumAsFlags<ErrorMode>
	{
		static constexpr ErrorMode max = ErrorMode::Max;
	};

	using ErrorModeFlags = Flags<ErrorMode>;

	enum class ErrorType
	{
		AssertFailed,
		Internal,
		Normal,
		Warning,

		Max = Warning
	};

	constexpr std::size_t ErrorTypeCount = static_cast<std::size_t>(ErrorType::Max) + 1;

	enum class ImageType
	{
		E1D,
		E1D_Array,
		E2D,
		E2D_Array,
		E3D,
		Cubemap,

		Max = Cubemap
	};

	constexpr std::size_t ImageTypeCount = static_cast<std::size_t>(ImageType::Max) + 1;

	enum class HashType
	{
		CRC32,
		CRC64,
		Fletcher16,
		MD5,
		SHA1,
		SHA224,
		SHA256,
		SHA384,
		SHA512,
		Whirlpool,

		Max = Whirlpool
	};

	constexpr std::size_t HashTypeCount = static_cast<std::size_t>(HashType::Max) + 1;

	enum class OpenMode
	{
		NotOpen,    // Use the current mod of opening

		Append,     // Disable writing on existing parts and put the cursor at the end
		Defer,      // Defer file opening until a read/write operation is performed on it
		Lock,       // Disable modifying the file before it is open
		MustExist,  // Fail if the file doesn't exists, even if opened in write mode
		ReadOnly,   // Open in read only
		Text,       // Open in text mod
		Truncate,   // Create the file if it doesn't exist and empty it if it exists
		Unbuffered, // Each read/write operation is equivalent to a read or write system call (slow)
		WriteOnly,  // Open in write only, create the file if it doesn't exist

		Max = WriteOnly
	};

	template<>
	struct EnumAsFlags<OpenMode>
	{
		static constexpr OpenMode max = OpenMode::Max;
	};

	using OpenModeFlags = Flags<OpenMode>;

	constexpr OpenModeFlags OpenMode_ReadWrite = OpenMode::ReadOnly | OpenMode::WriteOnly;

	enum class ParameterType
	{
		Boolean,
		Color,
		Double,
		Integer,
		None,
		Pointer,
		String,
		Userdata,

		Max = Userdata
	};

	enum class PrimitiveType
	{
		Box,
		Cone,
		Plane,
		Sphere,

		Max = Sphere
	};

	constexpr std::size_t PrimitiveTypeCount = static_cast<std::size_t>(PrimitiveType::Max) + 1;

	enum class ProcessorCap
	{
		x64,
		AES,
		AVX,
		FMA3,
		FMA4,
		MMX,
		Popcnt,
		RDRAND,
		XOP,
		SSE,
		SSE2,
		SSE3,
		SSSE3,
		SSE41,
		SSE42,
		SSE4a,

		Max = SSE4a
	};

	constexpr std::size_t ProcessorCapCount = static_cast<std::size_t>(ProcessorCap::Max) + 1;

	enum class ProcessorVendor
	{
		Unknown = -1,

		ACRN,
		AMD,
		Ao486,
		AppleRosetta2,
		Bhyve,
		Centaur,
		Cyrix,
		Elbrus,
		Hygon,
		HyperV,
		Intel,
		KVM,
		MicrosoftXTA,
		NSC,
		NexGen,
		Parallels,
		QEMU,
		QNX,
		Rise,
		SIS,
		Transmeta,
		UMC,
		VIA,
		VMware,
		Vortex,
		XenHVM,
		Zhaoxin,

		Max = Zhaoxin
	};

	constexpr std::size_t ProcessorVendorCount = static_cast<std::size_t>(ProcessorVendor::Max) + 1;

	enum class ResourceLoadingError
	{
		DecodingError,
		FailedToOpenFile,
		Internal,
		Unsupported,
		Unrecognized
	};

	enum class SphereType
	{
		Cubic,
		Ico,
		UV,

		Max = UV
	};

	enum class StreamOption
	{
		None,

		MemoryMapped,
		Sequential,
		Text,
		Unbuffered,

		Max = Unbuffered
	};

	template<>
	struct EnumAsFlags<StreamOption>
	{
		static constexpr StreamOption max = StreamOption::Max;
	};

	using StreamOptionFlags = Flags<StreamOption>;
}

#endif // NAZARA_CORE_ENUMS_HPP
