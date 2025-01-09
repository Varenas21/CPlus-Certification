#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <string>
#include <unordered_map>

using namespace std;

/*
* Flyweight Pattern
* 
* Reduces memory usage and creation costs of objects 
* Shares common data instead of replicating it in each object
* Improves performance and efficiency by sharing common data among objects
* 
* Pitfalls
* Increased Complexity
*/

#pragma region Example
// DOES NOT ACTUALLY DISPLAY IMAGE IT JUST HOLDS INFORMATION
class Texture
{
public:
	explicit Texture(const string& fileName) : m_FileName(fileName), m_ID(generateRandomID()) {}
	const string Description() const
	{
		return "<" + m_FileName + " ID" + to_string(m_ID) + ">";

	}
private:
	const string m_FileName;
	const int m_ID;

	static int generateRandomID()
	{
		static random_device rd;
		static mt19937 gen(rd());
		static uniform_int_distribution<> dist(0, numeric_limits<int>::max());
		return dist(gen);
	}
};

class Sprite
{
public:
	Sprite(const Texture *texture) : m_Texture(texture) 
	{
		cout << "Creating sprite with texture file " << texture->Description() << endl;
	}

	void setPositionSize(int x, int y, int width, int height)
	{
		m_X = x;
		m_Y = y;
		m_Width = width;
		m_Height = height;
	}

	void render()
	{
		cout << "Rendering sprite with texture: " << m_Texture->Description() << endl;
	}
private:
	int m_Width;
	int m_Height;
	int m_X;
	int m_Y;
	
	const Texture* m_Texture;

};

class SpriteFactory
{
public:
	Sprite* makeSprite(const string& fileName)
	{
		auto it = m_SpritePool.find(fileName);

		if (it != m_SpritePool.end())
		{
			return it->second;
		}
		else
		{
			const auto texture = getTexture(fileName);
			auto newIt = m_SpritePool.emplace(fileName, new Sprite(texture));
			return newIt.first->second;
		}
	}

private:
	unordered_map<string, Sprite*> m_SpritePool;
	unordered_map<string, Texture*> m_TexturePool;

	const Texture* getTexture(const string& fileName)
	{
		auto it = m_TexturePool.find(fileName);

		if (it != m_TexturePool.end())
		{
			// Texture already exists in pool, return it
			return it->second;
		}
		else
		{
			// Create new texture and add it to the pool
			auto newIt = m_TexturePool.emplace(fileName, new Texture(fileName));
			return newIt.first->second; // Access the iterator from the result
		}
	}
};

#pragma endregion
