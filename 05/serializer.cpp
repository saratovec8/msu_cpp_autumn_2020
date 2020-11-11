#include <iostream>
#include "serializer.h"

template <>
Error Serializer::save(const uint64_t &object)
{
	out_ << object << Separator;

	if (out_.fail())
	{
		return Error::CorruptedArchive;
	}
	else
	{
		return Error::NoError;
	}
}

template <>
Error Serializer::save<bool>(const bool &object)
{
	if (!object)
	{
		out_ << "false" << Separator;
	}
	else
	{
		out_ << "true" << Separator;
	}

	if (out_.fail())
	{
		return Error::CorruptedArchive;
	}
	else
	{
		return Error::NoError;
	}
}

template <>
Error Deserializer::load(uint64_t &object)
{
	in_ >> object;

	if (in_.fail())
	{
		return Error::CorruptedArchive;
	}
	else
	{
		return Error::NoError;
	}
}

template <>
Error Deserializer::load<bool>(bool &object)
{
	std::string str;
	in_ >> str;
	if (str == "false")
	{
		object = false;
	}
	else if (str == "true")
	{
		object = true;
	}
	else
	{
		return Error::CorruptedArchive;
	}
	return Error::NoError;
}


