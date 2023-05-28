#ifndef CHIP8X_DATA_H
#define CHIP8X_DATA_H

#pragma once

#include <cstdint>
#include <array>

//Convert BE CHIP8 opcode to LE format 
#define prefix(opcode) ((opcode >>12) & 0xF)
#define nnn(opcode) (opcode & 0x0FFF)
#define nn(opcode) (opcode & 0x0FF)
#define n(opcode) (opcode & 0x0F)
#define x(opcode) ((opcode >> 8) & 0x0F)
#define y(opcode) ((opcode >> 4) & 0x0F)

namespace info {
    constexpr uint32_t MEMORY_SIZE = 4096;
    constexpr uint32_t ROM_START_ADDRESS = 0x200; 
    const uint32_t ROM_MAX_SIZE = (MEMORY_SIZE - ROM_START_ADDRESS); // Maximum allowed size with respect to MEMORY_SIZE and address space
    constexpr uint32_t INTERNAL_SCREEN_WIDTH = 64; // CHIP8 original X resolution
    constexpr uint32_t INTERNAL_SCREEN_HEIGHT = 32; // CHIP8 original Y resolution 
    const uint32_t INTERNAL_SCREEN_PIXELS = (INTERNAL_SCREEN_WIDTH*INTERNAL_SCREEN_HEIGHT); // CHIP8 original resolution pixel amount
    constexpr uint32_t SCALE_FACTOR = 20; // Default resolution: 1280x640
    constexpr uint32_t FG_COLOR = 0xFFFFFFFF; // Foreground color RGBA8888; WHITE
    constexpr uint32_t BG_COLOR = 0x000000FF; // Background color RGBA8888; BLACK
}

constexpr std::array<uint8_t, 80> font_set = {
		0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
		0x20, 0x60, 0x20, 0x20, 0x70, // 1
		0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
		0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
		0x90, 0x90, 0xF0, 0x10, 0x10, // 4
		0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
		0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
		0xF0, 0x10, 0x20, 0x40, 0x40, // 7
		0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
		0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
		0xF0, 0x90, 0xF0, 0x90, 0x90, // A
		0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
		0xF0, 0x80, 0x80, 0x80, 0xF0, // C
		0xE0, 0x90, 0x90, 0x90, 0xE0, // D
		0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
		0xF0, 0x80, 0xF0, 0x80, 0x80  // F
	};

#endif //CHIP8X_DATA_H