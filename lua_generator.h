#ifndef STARLIGHT_PROTOBUF_COMPILER_LUA_GENERATOR_H
#define STARLIGHT_PROTOBUF_COMPILER_LUA_GENERATOR_H

#include <google/protobuf/compiler/code_generator.h>

namespace starlight
{
	namespace protobuf
	{
		namespace compiler
		{
			namespace lua
			{
				class Generator
					: public google::protobuf::compiler::CodeGenerator
				{
				public:
					virtual bool Generate(const google::protobuf::FileDescriptor* file, const std::string& parameter, google::protobuf::compiler::GeneratorContext* generator_context, std::string* error) const override;
				};
			}
		}
	}
}

#endif // STARLIGHT_PROTOBUF_COMPILER_LUA_GENERATOR_H ///:~
