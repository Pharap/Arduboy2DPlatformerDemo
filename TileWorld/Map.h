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

#include "TileType.h"

class Map
{
private:
	uint8_t width = 0;
	uint8_t height = 0;
	const TileType * data = nullptr;

	// Calculates array index from coordinates
	constexpr size_t getIndex(uint8_t x, uint8_t y) const
	{
		return ((y * width) + x);
	}

public:
	constexpr Map() = default;

	constexpr Map(uint8_t width, uint8_t height, const TileType * mapData)
		: width(width), height(height), data(mapData)
	{
	}

	template< uint8_t width, uint8_t height >
	constexpr Map(const TileType (&mapData)[height][width])
		: width(width), height(height), data(&mapData[0][0])
	{
	}

	constexpr uint8_t getWidth() const
	{
		return this->width;
	}

	constexpr uint8_t getHeight() const
	{
		return this->height;
	}

	TileType getTile(uint8_t x, uint8_t y) const
	{
		// If coordinate is out of bounds
		if((x > this->width) || (y > this->height))
		{
			// Return 'void' tile
			return TileType::Void;
		}

		// Calculate array index
		const size_t index = this->getIndex(x, y);

		// Get pointer to tile data
		const TileType * tilePointer = &this->data[index];

		// Read tile data from progmem
		return readTileTypeFromProgmem(tilePointer);
	}

	TileType getTile(int16_t x, int16_t y) const
	{
		// If coordinate is out of bounds
		if((x < 0) || (y < 0) || (x > this->width) || (y > this->height))
		{
			// Return 'void' tile
			return TileType::Void;
		}

		// Calculate array index
		const size_t index = this->getIndex(x, y);

		// Get pointer to tile data
		const TileType * tilePointer = &this->data[index];

		// Read tile data from progmem
		return readTileTypeFromProgmem(tilePointer);
	}
};