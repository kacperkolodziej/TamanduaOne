#ifndef TAMANDUA_MESSAGE_HEADER_HPP
#define TAMANDUA_MESSAGE_HEADER_HPP

#include "config/message_types.hpp"
#include "config/tamandua_api.hpp"

namespace tamandua {

using namespace config;

const size_t author_name_size = 40;

struct TAMANDUA_API MessageHeader
{
	MessageId msg_id;
	MessageType type;
	ErrorCode error_code;
	AuthorId author_id;
	GroupId group_id;
	UTCTime utc_time;
	MessageSize size;
	MessageOptions options;
	MessageByte author_name[author_name_size];
};

}

#endif
