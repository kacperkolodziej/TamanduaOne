#include "message_composer.hpp"

#include <cstring>

#include "message.hpp"

namespace tamandua {

MessageComposer::MessageComposer(config::MessageType type, config::AuthorId author_id, std::string author_name, config::GroupId group_id)
{
	header_.type = type;
	header_.author_id = author_id;
	if (author_name.empty() == false)
	{
		strcpy(header_.author_name, author_name.substr(0,author_name_size).data());
	}
	header_.group_id = group_id;
}

MessageComposer::MessageComposer(config::MessageType type, std::string data, config::AuthorId author_id, std::string author_name, config::GroupId group_id)
{
	header_.type = type;
	header_.author_id = author_id;
	if (author_name.empty() == false)
	{
		strcpy(header_.author_name, author_name.substr(0,author_name_size).data());
	}
	header_.group_id = group_id;
	body_stream_ << data;
}

Message MessageComposer::message()
{
	std::string msg_body =  body_stream_.str();
	header_.size = msg_body.length();
	return Message(header_, msg_body);
}

} // namespace tamandua
