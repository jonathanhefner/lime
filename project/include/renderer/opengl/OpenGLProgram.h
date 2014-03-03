#ifndef RENDERER_OPENGL_PROGRAM_H
#define RENDERER_OPENGL_PROGRAM_H


#include "renderer/opengl/OGL.h"
#include "renderer/common/GPUProgram.h"


namespace lime {
	
	
	class OpenGLProgram : public GPUProg {
		
		public:
			
			OpenGLProgram (const std::string &inVertProg, const std::string &inFragProg);
			virtual ~OpenGLProgram ();
			
			virtual bool bind ();
			virtual void setGradientFocus (float inFocus);
			
			GLuint createShader (GLuint inType, const char *inShader);
			void disableSlots ();
			int getTextureSlot ();
			void recreate ();
			void setColourTransform (const ColorTransform *inTransform, unsigned int inColour);
			void setTransform (const Trans4x4 &inTrans);
			
			int getProgramID();
			
			void applyUniforms();
			
			GLint mASlot;
			GLint mColourArraySlot;
			GLint mColourOffsetSlot;
			GLint mColourScaleSlot;
			const ColorTransform *mColourTransform;
			int mContextVersion;
			GLuint mFragId;
			std::string mFragProg;
			GLint mFXSlot;
			GLint mImageSlot;
			GLint mOn2ASlot;
			GLuint mProgramId;
			GLint mTransformSlot;
			GLuint mVertId;
			std::string mVertProg;
			
			//GLint colourSlot;
			//GLint normalSlot;
			//GLint textureSlot;
			//GLint vertexSlot;
		
	};
	
	
}


#endif
