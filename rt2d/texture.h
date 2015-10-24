/**
 * @file texture.h
 * 
 * @brief The Texture header file.
 * 
 * This file is part of RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *   - Initial commit
 * - Copyright [year] [your name] <you@yourhost.com>
 *   - [description]
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

#include <GL/glew.h>

#include <glfw3.h>

/// @brief The Texture class loads images from files and converts them to OpenGL textures.
class Texture
{
	public:
		Texture();			///< @brief Constructor of the Texture
		virtual ~Texture();	///< @brief Destructor of the Texture

		/// @brief get the OpenGL texture
		/// @return GLuint _texture
		GLuint getGLTexture() { return _texture; };

		/// @brief get the width of the OpenGL texture
		/// @return int _width
		int width() { return _width; };
		/// @brief get the height of the OpenGL texture
		/// @return int _height
		int height() { return _height; };

		/// @brief load an image from file (tga only)
		/// @param filename the path to the image
		/// @return GLuint _texture, 0 if failed
		GLuint loadImage(const std::string& filename);
		/// @brief Autogenerates white RGB texture
		/// @param width the width of the white Texture
		/// @param height the height of the white Texture
		/// @return GLuint _texture, 0 if failed
		GLuint createWhite(int width, int height);
	
	private:
		GLuint _texture;	///< @brief texture handle
		int _width;			///< @brief texture width
		int _height;		///< @brief texture height

		/// @brief save filter level for this Texture
		int _filtering;
		/**
		 * @brief level of filtering
		 * 
		 * 0 = no filtering.
		 * 1 = Linear filtering.
		 * 2 = Bilinear filtering.
		 * 3 = Trilinear filtering.
		 * 
		 * @param level
		 */
		void _filterTexture(int level);

		/// @brief load a tga from file
		/// @param imagepath the path to the image.tga
		/// @return GLuint _texture
		GLuint loadTGA(const char * imagepath);
};

#endif
