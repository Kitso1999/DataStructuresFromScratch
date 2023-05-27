#pragma once

#ifndef __KITS_ALLOCATOR_H__
#define __KITS_ALLOCATOR_H__

#include <cstddef>
#include <utility>
#include <new>
#include <xmemory>

namespace kits {
	template<class T>
	class allocator {
	public:

		using byte_type = unsigned char;

		using size_type = std::size_t;

		constexpr allocator() noexcept = default;
		constexpr allocator(const allocator&) noexcept = default;
		template<class Other>
		constexpr allocator(const allocator<Other>&) noexcept {}
		inline ~allocator() = default;
		constexpr allocator& operator=(const allocator&) = default;

		[[nodiscard]] constexpr T* allocate(const std::size_t t_count) {
			return reinterpret_cast<T*>(::operator new (t_count * sizeof(T), std::align_val_t{alignof(T)}) );
		}
		
		template<class... Types>
		constexpr void construct(T* const t_ptr, Types&&... t_args) {
			::new (reinterpret_cast<void*>(t_ptr)) T(std::forward<Types>(t_args)...);
		}

		constexpr void deallocate(T* t_ptr) {
			::operator delete(reinterpret_cast<byte_type*>(t_ptr), std::align_val_t{alignof(T)});
		}

		constexpr void destroy(T* t_ptr) {
			t_ptr->~T();
		}

		constexpr size_type max_size() const noexcept {
			return static_cast<size_type>(-1) / sizeof(T);
		}

	}; // class allocator

}; // namespace kits

#endif //__KITS_ALLOCATOR_H__