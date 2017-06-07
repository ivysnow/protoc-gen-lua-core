#ifndef STARLIGHT_PROTOBUF_COMPILER_LUA_FILEGENERATOR_H
#define STARLIGHT_PROTOBUF_COMPILER_LUA_FILEGENERATOR_H

#include <memory>
#include <string>
#include <tuple>
#include <unordered_map>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/compiler/code_generator.h>
#include <google/protobuf/io/printer.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include "lua_options.h"

namespace starlight
{
	namespace protobuf
	{
		namespace compiler
		{
			namespace lua
			{
				class FileGenerator
				{
				public:
					FileGenerator(const google::protobuf::FileDescriptor* file, google::protobuf::compiler::GeneratorContext* context, Options options);

				public:
					void Generate();

				private:
					void GenerateImport();
					void GenerateDependency(const google::protobuf::FileDescriptor* dependency);
					void GenerateExport();
					void GenerateDescriptors();
					void GenerateEnumDescriptor(const google::protobuf::EnumDescriptor* enumType);
					void GenerateMessageDescriptor(const google::protobuf::Descriptor* messageType);
					void GenerateVariables();
					void GenerateEnumVariables(const google::protobuf::EnumDescriptor* enumType);
					void GenerateMessageVariables(const google::protobuf::Descriptor* messageType);
					void GenerateReturn();

				private:
					void ParseSymbolNames(const google::protobuf::FileDescriptor* file, const std::string& moduleName = {});
					void ParseEnumName(const google::protobuf::EnumDescriptor* enumType, const std::string& moduleName);
					void ParseMessageName(const google::protobuf::Descriptor* messageType, const std::string& moduleName);
					void ParseName(const std::string& fullName, const std::string& name, const std::string& moduleName, const std::string& lastSeperate);
					const std::string& ResolveName(const std::string& fullName) const;
					const std::string& ResolveVarName(const std::string& fullName) const;

				private:
					Options m_options;
					const google::protobuf::FileDescriptor* m_file;
					std::unique_ptr<google::protobuf::io::ZeroCopyOutputStream> m_output;
					google::protobuf::io::Printer m_printer;
					std::unordered_map<std::string, std::tuple<std::string, std::string>> m_nameMap; // <full_name, <name, varname>>
				};
			}
		}
	}
}

#endif // STARLIGHT_PROTOBUF_COMPILER_LUA_FILEGENERATOR_H ///:~
