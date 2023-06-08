#pragma once

#include "allocator.h"

#include <cassert>

#ifndef __KITS_VECTOR_H__
#define __KITS_VECTOR_H__

namespace kits {

	template<class T, class Alloc = allocator<T>>
	class vector {
		using size_type = std::size_t;

		static constexpr size_type kMinCapacity{4};

	public:
		constexpr vector() = default;
		constexpr vector(const vector&) = default;
		constexpr vector(vector&&) = default;
		constexpr vector& operator=(const vector&) = default;
		constexpr vector& operator=(vector&&) = default;
		~vector() { 
			if (!buf_)
				return;
			for (size_type i = 0; i < size_; ++i) {
				allocator_.destroy(&buf_[i]);
			}

			allocator_.deallocate(buf_);
			 
		}

		void push_back(const T& val) {
			size_type old_size = size_;
			size_type old_capacity = capacity_;
			T* old_buf = buf_;

			if (!old_buf) {
				buf_ = allocator_.allocate(kMinCapacity);
				capacity_ = kMinCapacity;
			}
			else {
				if (old_size == old_capacity) {
					const size_type new_capacity = old_capacity * 2;
					T* new_buf = allocator_.allocate(new_capacity);

					for (size_type i = 0; i < size_; ++i) {
						allocator_.construct(&new_buf[i], buf_[i]);
					}

					buf_ = new_buf;
					capacity_ = new_capacity;
				}
			}

			allocator_.construct(&buf_[size_++], val);

			for (size_type i = 0; i < old_size; ++i) {
				allocator_.destroy(&old_buf[i]);
			}
			if (old_buf) {
				allocator_.deallocate(old_buf);
			}
		}

		void pop_back() {
			assert(size_ && "Can not pop_back from empty array");

			allocator_.destroy(&buf_[size_--]);
		}

	private:

		Alloc allocator_;
		T* buf_{};
		size_type size_{};
		size_type capacity_{};
	};
}

#endif //__KITS_VECTOR_H__