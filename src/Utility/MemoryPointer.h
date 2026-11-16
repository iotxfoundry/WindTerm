// [B-OPENSOURCE] 第一方开源件 —— **勿逆向**。
// 这是 WindTerm 作者以 Apache-2.0 开源的一手组件(基于上游 ptyqt / 自研),不是反编译对象;
// 移植或修改须按 docs/calibration.md 逐句同构记录。分类依据见 src/README.md §1b。

#ifndef MEMORYPOINTER_H
#define MEMORYPOINTER_H

#pragma once

#include <QtGlobal>

template <typename T>
struct MemoryPointer {
	typedef decltype(nullptr) nullptr_t;

public:
	MemoryPointer()
		: uMemory({ 0 })
	{}

	MemoryPointer(const MemoryPointer &other) = delete;
	MemoryPointer &MemoryPointer::operator=(const MemoryPointer &other) = delete;

	MemoryPointer &MemoryPointer::operator=(nullptr_t) noexcept {
		free();

		uMemory = { 0 };
		return (*this);
	}

	MemoryPointer(MemoryPointer &&other) noexcept {
		uMemory = other.uMemory;
		other.uMemory = { 0 };
	}

	MemoryPointer& MemoryPointer::operator=(MemoryPointer &&other) noexcept	{
		if (this != &other) {
			free();
			
			uMemory = other.uMemory;
			other.uMemory = { 0 };
		}
		return (*this);
	}

	~MemoryPointer() {
		free();
	}

	inline T *data() const {
		return static_cast<T *>(uMemory.pointer);
	}

	inline T *operator->() const {
		return data();
	}

	inline T &operator*() const {
		return *data();
	}

	inline operator T*() const {
		return data();
	}

	inline operator bool() const noexcept {
		return data() != nullptr;
	}

	inline bool isNull() const {
		return uMemory.pointer == NULL;
	}

private:
	void free() {
		if (uMemory.alloced) {
			::free(reinterpret_cast<void *>(uMemory.pointer));
			uMemory = { 0 };
		}
	}

private:
	union MemoryUnion {
		quint64 value;

		struct {
			quint64 alloced : 1;
			quint64 pointer : 48;
		};
	};
	MemoryUnion uMemory;
};

template <class T>
inline bool operator==(const T *o, const MemoryPointer<T> &p) {
	return o == p.operator->();
}

template<class T>
inline bool operator==(const MemoryPointer<T> &p, const T *o) {
	return p.operator->() == o;
}

template <class T>
inline bool operator==(T *o, const MemoryPointer<T> &p) {
	return o == p.operator->();
}

template<class T>
inline bool operator==(const MemoryPointer<T> &p, T *o) {
	return p.operator->() == o;
}

template<class T>
inline bool operator==(const MemoryPointer<T> &lhs, const MemoryPointer<T> &rhs) {
	return lhs.operator->() == rhs.operator->();
}

template <class T>
inline bool operator!=(const T *o, const MemoryPointer<T> &p) {
	return o != p.operator->();
}

template<class T>
inline bool operator!= (const MemoryPointer<T> &p, const T *o) {
	return p.operator->() != o;
}

template <class T>
inline bool operator!=(T *o, const MemoryPointer<T> &p) {
	return o != p.operator->();
}

template<class T>
inline bool operator!= (const MemoryPointer<T> &p, T *o) {
	return p.operator->() != o;
}

template<class T>
inline bool operator!= (const MemoryPointer<T> &lhs, const MemoryPointer<T> &rhs) {
	return lhs.operator->() != rhs.operator->();
}

#endif // MEMORYPOINTER_H