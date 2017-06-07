#include "lua_generator.h"
#include "lua_filegenerator.h"

using namespace std;
using namespace google::protobuf;
using namespace google::protobuf::compiler;
using namespace google::protobuf::io;
using namespace starlight::protobuf::compiler::lua;

bool Generator::Generate(const FileDescriptor* file, const string& parameter, GeneratorContext* generator_context, string* error) const
{
	vector<pair<string, string>> options;
	ParseGeneratorParameter(parameter, &options);

	Options file_options;
	for (auto& option : options)
	{
		if (option.first == "unity")
		{
			file_options.unity = option.second;
		}
	}

	FileGenerator(file, generator_context, file_options).Generate();
	return true;
}
