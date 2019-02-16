#pragma once

//
// Copyright (C) 2019 Pharap (@Pharap)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <stdint.h>

enum class TileType : uint8_t
{
	None,
	Grass,
	Dirt,
	Void,
};

// Returns 'true' if a tile is solid
constexpr bool isSolid(TileType tileType)
{
	// Currently all tiles apart from 'None' are solid
	return (tileType != TileType::None);
}

constexpr uint8_t getTileIndex(TileType tileType)
{
	// Convert TileType into index usable for array indexing
	return static_cast<uint8_t>(tileType);
}

TileType readTileTypeFromProgmem(const TileType * progmem)
{
	// Read byte from progmem, convert to TileType
	return static_cast<TileType>(pgm_read_byte(progmem));
}