#ifndef RENDERER_GPUPROGRAM_H
#define RENDERER_GPUPROGRAM_H

#include <Graphics.h>
#include <Object.h>

namespace lime 
{
	
	typedef float Trans4x4[4][4];
	class GPUProg : public Object {
		
	public:
	   GPUProg() { ++_current_id; }	
	   static GPUProg *create(unsigned int inID);
	   
	   virtual ~GPUProg() {}

	   virtual bool bind() = 0;

	   virtual void disableSlots() = 0;
	   virtual void setTransform(const Trans4x4 &inTrans) = 0;
	   virtual void setColourTransform(const ColorTransform *inTransform, unsigned int inColour) = 0;
	   virtual void setGradientFocus(float inFocus) = 0;
	   
	   virtual int getProgramID() = 0;
	   virtual void applyUniforms() = 0;
	   
	   int vertexSlot;
	   int textureSlot;
	   int normalSlot;
	   int colourSlot;
	
    protected:
	   int ID;
	   static int _current_id;	
	};

}


#endif //RENDERER_GPUPROGRAM_H