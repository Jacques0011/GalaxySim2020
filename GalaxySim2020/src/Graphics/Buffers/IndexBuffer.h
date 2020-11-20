#pragma once
#include "GL/glew.h"
namespace Graphics {
	class IndexBuffer
	{
	private:
		unsigned int m_id;
	public:
		IndexBuffer(const unsigned int* data, size_t size);
		~IndexBuffer();
		inline void bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id); }
		inline void unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

		inline unsigned int getId() { return m_id; }
	};
}
