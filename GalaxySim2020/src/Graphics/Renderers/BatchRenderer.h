#pragma once
#include <list>
#include <vector>
#include <map>
#include "../Graphics/Primatives/vertex.h"
#include "../Graphics/Shapes/renderable.h"
#include "../Graphics/Buffers/VertexArrayObj.h"
#include "../Graphics/Buffers/IndexBuffer.h"
#include "../Graphics/Buffers/VertexBuffer.h"
#include "Graphics/Shaders/ShaderProgram.h"

namespace Graphics
{
	struct batch {
		std::vector<vertex> m_vertices;
		size_t m_vertArrayIndexPtr = 0;
		std::vector<uint32_t> m_indices;
		size_t m_indArrayIndexPtr = 0;
		std::map<int ,Texture2D*> m_textureBinding;
	};
#define DEFAULT_MAX_VERTS 20000
// The default index ratio is 3/2 because with quads there are 3 indicices for every 2 vertices. This is only a guess at a good 
// ratio. More complex ratios might need to be explored later.
#define DEFAULT_INDEX_RATIO 1.5f

	class BatchRenderer
	{
	private:
		//vertex data to be stored until sent to gpu
		std::list<batch*> batches;
		const uint32_t m_maxVerts;
		const uint32_t m_maxIndicies;
		IndexBuffer m_indexBuf;
		VertexBuffer m_vertexBuf;
		VertexArrayObj m_vao;
		uint32_t m_shaderProgramID;
		//s_maxTextureUnits should be thought of as effectively const
		static int s_maxTextureUnits;
	public:
		BatchRenderer(ShaderProgram& shader);
		BatchRenderer(ShaderProgram& shader, uint32_t maxVerts, float indexRatio);
		~BatchRenderer();
		static int getMaxTextureUnits();
		void addMesh(renderable& mesh);
		void render();

	private:
		inline bool hasSameShader(const renderable& mesh) { return mesh.getShaderProgram() == m_shaderProgramID; }
		void offsetIndices(const std::pair<uint32_t*, size_t> indexData, std::vector<uint32_t>& out, uint32_t offset);
		void setVertexTextureBinding(vertex& vert, batch& batch);
		bool hasTextureBinding(renderable& mesh, batch& batch);
		bool canAddTextureBinding(renderable& mesh, batch& batch);
		void addTextureBinding(renderable& mesh, batch& batch);
	};
}

