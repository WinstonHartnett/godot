/**************************************************************************/
/*  thread_safe.cpp                                                       */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef THREAD_SAFE_CPP
#define THREAD_SAFE_CPP

#include "thread_safe.h"

static thread_local uint8_t current_thread_safety = 0; // by default, checks disabled

const uint8_t node_safe_mask = 1 << 0;
const uint8_t scene_safe_mask = 1 << 1;

bool is_current_thread_safe_for_nodes() {
	return (current_thread_safety & node_safe_mask) >> 0;
}

bool is_current_thread_safe_for_scene_tree() {
	return (current_thread_safety & scene_safe_mask) >> 1;
}

void set_current_thread_safe_for_nodes(bool p_safe) {
	current_thread_safety = (current_thread_safety & ~node_safe_mask) | p_safe;
}

void set_current_thread_safe_for_scene_tree(bool p_safe) {
	current_thread_safety = (current_thread_safety & ~scene_safe_mask) | p_safe;
}

#endif // THREAD_SAFE_CPP
