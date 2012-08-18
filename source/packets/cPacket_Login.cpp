
#include "Globals.h"  // NOTE: MSVC stupidness requires this to be the same across all modules

#include "cPacket_Login.h"





const char * cPacket_Login::LEVEL_TYPE_DEFAULT   = "DEFAULT";
const char * cPacket_Login::LEVEL_TYPE_SUPERFLAT = "SUPERFLAT";





int cPacket_Login::Parse(cByteBuffer & a_Buffer)
{
	int TotalBytes = 0;
	m_Username.clear();
	HANDLE_PACKET_READ(ReadBEInt,           m_ProtocolVersion, TotalBytes);
	HANDLE_PACKET_READ(ReadBEUTF16String16, m_Username,        TotalBytes);
	HANDLE_PACKET_READ(ReadBEUTF16String16, m_LevelType,       TotalBytes);
	HANDLE_PACKET_READ(ReadBEInt,           m_ServerMode,      TotalBytes);
	HANDLE_PACKET_READ(ReadBEInt,           m_Dimension,       TotalBytes);
	HANDLE_PACKET_READ(ReadChar,            m_Difficulty,      TotalBytes);
	HANDLE_PACKET_READ(ReadByte,            m_WorldHeight,     TotalBytes);
	HANDLE_PACKET_READ(ReadByte,            m_MaxPlayers,      TotalBytes);
	return TotalBytes;
}





void cPacket_Login::Serialize(AString & a_Data) const
{
	AppendByte    (a_Data, m_PacketID);
	AppendInteger (a_Data, m_ProtocolVersion);
	AppendString16(a_Data, m_Username);
	AppendString16(a_Data, m_LevelType);
	AppendInteger (a_Data, m_ServerMode);
	AppendInteger (a_Data, m_Dimension);
	AppendByte    (a_Data, m_Difficulty);
	AppendByte    (a_Data, m_WorldHeight);
	AppendByte    (a_Data, m_MaxPlayers);
}




