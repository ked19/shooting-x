// SDK v1.2.42
#ifndef __KMPEG4_UNIFICATION_SDK
#define __KMPEG4_UNIFICATION_SDK

#define DLL_API extern "C" __declspec(dllimport)
//#define DLL_API extern "C" __declspec(dllexport)
//#define DLL_API 

// ked
#include<Windows.h>

#define SDK10000_ERROR_NO_ERROR								0
#define SDK10000_ERROR_AVC_ADAPTOR_ATTACHED_ALREADY			1
#define SDK10000_ERROR_CODEC_ADAPTOR_ATTACHED_ALREADY		2
#define SDK10000_ERROR_FILE_ADAPTOR_ATTACHED_ALREADY		3
#define SDK10000_ERROR_DRAWER_ADAPTOR_ATTACHED_ALREADY		4

#define SDK10000_ERROR_CAN_NOT_LOAD_AVC_ADAPTOR				11
#define SDK10000_ERROR_CAN_NOT_LOAD_CODEC_ADAPTOR			12
#define SDK10000_ERROR_CAN_NOT_LOAD_FILE_ADAPTOR			13
#define SDK10000_ERROR_CAN_NOT_LOAD_DRAWER_ADAPTOR			14

#define SDK10000_ERROR_BAD_URL_COMMAND						22
#define SDK10000_ERROR_BAD_IP_OR_PORT						23
#define SDK10000_ERROR_BAD_PARAMETER						24
#define SDK10000_ERROR_NO_CONNECTION						25
#define SDK10000_ERROR_TCP10_NOT_SUPPORTED_SOUND_DEVICE		26
#define SDK10000_ERROR_AUDIO_TOKEN_WAS_TAKEN				27
#define SDK10000_ERROR_HAVE_NO_AUDIO_TOKEN					28
#define SDK10000_ERROR_FAIL_TO_INIT_AUDIO_CAPTURE_DEVICE	29
#define SDK10000_ERROR_CREATE_FILE_FAIL						30
#define SDK10000_ERROR_CONNECT_FAIL							31
#define SDK10000_ERROR_START_STREAMING_FAIL					32 // please check ID and password

#define DI_DEFAULT_IS_LOW		0x00	///< Digital Input Default is Low
#define DI_DEFAULT_IS_HIGH		0x03	///< Digital Input Default is High

#define DO_OUTPUT_1				0x01	///< Digital Output 1st
#define DO_OUTPUT_2				0x02	///< Digital Output 2nd
#define DO_OUTPUT_BOTH			0x03	///< Digital Output Both 1st & 2nd
#define DO_OUTPUT_CLEAN			0x00	///< Clen up Digital Output

#define RS232_SET_N81			0x00	///< RS232 Setting, N,    8, 1
#define RS232_SET_O81			0x08	///< RS232 Setting, Odd,  8, 1
#define RS232_SET_E81			0x18	///< RS232 Setting, Even, 8, 1

enum DeviceType
{
	_SINGLE_CHANNEL_VIDEO_SERVER = 0,
	_ACD2000Q_VIDEO_SERVER,
	_SED2300Q_VIDEO_SERVER,
	_AUTO_DETECT,
};

enum PLAY_RATES /** Play rate */
{ 
	RATE_0_5, ///< #0# - 1/2 Speed
	RATE_1_0, ///< #1# - 1.0 Speed
	RATE_2_0, ///< #2# - 2.0 Speed
	RATE_4_0, ///< #3# - 4.0 Speed
	RATE_8_0  ///< #4# - 8.0 Speed
};

typedef enum {
	CONTACT_TYPE_UNUSE = 0,
	CONTACT_TYPE_UNICAST_WOC_PREVIEW=1,
	CONTACT_TYPE_MULTICAST_WOC_PREVIEW,
	CONTACT_TYPE_RTSP_PREVIEW,
	CONTACT_TYPE_CONTROL_ONLY,
	CONTACT_TYPE_UNICAST_PREVIEW,
	CONTACT_TYPE_MULTICAST_PREVIEW,
	CONTACT_TYPE_PLAYBACK,
	CONTACT_TYPE_CARD_PREVIEW,

	CONTACT_TYPE_MULTIPLE_PLAYBACK,
	CONTACT_TYPE_HTTP_RTSP_WOC_PREVIEW,
	CONTACT_TYPE_HTTP_RTSP_PREVIEW,

	CONTACT_TYPE_HTTP,

	CONTACT_TYPE_RTSP_RTPUDP_PREVIEW,
	CONTACT_TYPE_RTSP_RTPUDP_WOC_PREVIEW,
	CONTACT_TYPE_RTSP_RTPTCP_PREVIEW,
	CONTACT_TYPE_RTSP_RTPTCP_WOC_PREVIEW,

	CONTACT_TYPE_HTTP_WOC_PREVIEW,
	CONTACT_TYPE_HTTP_PREVIEW,
	CONTACT_TYPE_HTTP_CONTROL_ONLY,
	CONTACT_TYPE_HTTP_MESSAGE, // dual session ; listen and POST Message

	CONTACT_TYPE_FTP_PLAYBACK,
	CONTACT_TYPE_HTTP_PLAYBACK,
	CONTACT_TYPE_HTTP_MIME,
	//CONTACT_TYPE_HTTP_REMOTE_PLAYBACK,         // Remote Playback (search/play)
	//CONTACT_TYPE_HTTP_AUDIO_TRANSFER,          // Send Audio to Device

	CONTACT_TYPE_PLAYBACK_AVI = 60,

	CONTACT_TYPE_MAX,
}CONTACT_TYPE;

enum RS232_BAUD_RATE		/** RS232 BaudRate */
{
	BAUD_RATE_1200BPS,		///< #0# - 1200 BPS
	BAUD_RATE_2400BPS,		///< #1# - 2400 BPS
	BAUD_RATE_4800BPS,		///< #2# - 4800 BPS
	BAUD_RATE_9600BPS,		///< #3# - 9600 BPS
	BAUD_RATE_19200BPS,		///< #4# - 19200 BPS
	BAUD_RATE_38400BPS,		///< #5# - 38400 BPS
	BAUD_RATE_57600BPS,		///< #6# - 57600 BPS
	BAUD_RATE_115200BPS,	///< #7# - 115200 BPS
	BAUD_RATE_230400BPS		///< #8# - 230400 BPS
};

enum BITRATE_TYPES			/** Bitrate Types */
{
	BITRATE_28K,			///< #0# - 28K Bits per second
	BITRATE_56K,			///< #1# - 56K Bits per second
	BITRATE_128K,			///< #2# - 128K Bits per second
	BITRATE_256K,			///< #3# - 256K Bits per second
	BITRATE_384K,			///< #4# - 384K Bits per second
	BITRATE_500K,			///< #5# - 500K Bits per second
	BITRATE_750K,			///< #6# - 750K Bits per second
	BITRATE_1000K,			///< #7# - 1M Bits per second
	BITRATE_1200K,			///< #8# - 1.2M Bits per second
	BITRATE_1500K,			///< #9# - 1.5M Bits per second
	BITRATE_2000K,			///< #10# - 2M Bits per second
	BITRATE_2500K,			///< #11# - 2.5M Bits per second
	BITRATE_3000K,			///< #12# - 3M Bits per second
	BITRATE_3500K,			///< #13# - 3.5M Bits per second
	BITRATE_4000K,			///< #14# - 4M Bits per second
	BITRATE_4500K,			///< #15# - 4.5M Bits per second
	BITRATE_5000K,			///< #16# - 5M Bits per second
	BITRATE_5500K,			///< #17# - 5.5M Bits per second
	BITRATE_6000K,			///< #18# - 6M Bits per second
};


enum PTZ_MOVE_OPERATION
{
	PTZ_MOVE_UP, 
	PTZ_MOVE_DOWN, 
	PTZ_MOVE_LEFT, 
	PTZ_MOVE_RIGHT, 
	PTZ_MOVE_UP_LEFT, 
	PTZ_MOVE_UP_RIGHT, 
	PTZ_MOVE_DOWN_LEFT,
	PTZ_MOVE_DOWN_RIGHT, 
	PTZ_MOVE_STOP
};

enum PTZ_ZOOM_OPERATION
{
	PTZ_ZOOM_IN,
	PTZ_ZOOM_OUT, 
	PTZ_ZOOM_STOP
};

enum PTZ_RESEST_OPERATION
{
	PTZ_PRESET_SET,
	PTZ_PRESET_GOTO 
};

enum PTZ_OSD_OPERATION
{
	PTZ_OSD_ON, 
	PTZ_OSD_OFF, 
	PTZ_OSD_UP, 
	PTZ_OSD_DOWN,
	PTZ_OSD_LEFT, 
	PTZ_OSD_RIGHT, 
	PTZ_OSD_ENTER, 
	PTZ_OSD_LEAVE,
	PTZ_OSD_STOP
};

enum PTZ_BLC_OPERATION
{
	PTZ_BLC_ON, 
	PTZ_BLC_OFF
};

enum PTZ_DN_OPERATION
{
	PTZ_DN_ON,
	PTZ_DN_OFF,
	PTZ_DN_AUTO_ON,
	PTZ_DN_AUTO_OFF
};

enum PTZ_FOCUS_OPERATION
{
	PTZ_FOCUS_IN, 
	PTZ_FOCUS_OUT,
	PTZ_FOCUS_STOP
};

enum PTZ_IRIS_OPERATION
{
	PTZ_IRIS_OPEN,
	PTZ_IRIS_CLOSE,
	PTZ_IRIS_STOP, 
	PTZ_IRIS_AUTO
};

#define XNTSC720x480	0x00	// (D1)
#define XNTSC352x240	0x01	// (CIF)
#define XNTSC160x112	0x02	// (QCIF)
#define XNTSC176x120	0x06	// (QCIF)

#define XNTSC640x480	0x40	// (VGA)
#define XNTSC1280x720	0x41	// (720P)
#define XNTSC1280x960	0x42
#define XNTSC1280x1024	0x43
#define XNTSC1600x1200	0x44

#define XNTSC1920x1080	0x45
#define XNTSC160x120	0x47	// (QQVGA)
#define XNTSC320x240	0x46	// (QVGA)
#define XNTSC2032x1920	0x48
#define XNTSC1280x352	0x49 
#define XNTSC1920x1072	0x4A
#define XNTSC2592x1944	0x4B     
#define XNTSC2048x1536	0x4C

#define N2592x1944		0x4B  
#define N2048x1536		0x4C
#define N640x360		0x4D
#define N2032x1944		0x4E
#define N2032x1936		0x4F

#define N3648x2736		0x50 
#define N800x480		0x51 
#define N800x600		0x52 
#define N1024x576		0x53 
#define N1024x768		0x54
#define N1280x800		0x55
#define N1376x768		0x56
#define N1440x912		0x57
#define N1680x1056		0x58
#define N1920x1440		0x59
#define N3072x2048		0x5A
#define N3840x2160		0x5B
#define N3648x2160		0x5C


#define N3840x2160 0x5B 
#define N1440x1080 0x5D  
#define N2560x1440 0x5E  
#define N2688x1520 0x5F  


#define N240x320 0x70 
#define N360x640 0x71 
#define N480x640 0x72 
#define N720x1280 0x73 
#define N960x1280 0x74 
#define N1080x1920 0x75 
#define N1536x2048 0x76 
#define N1944x2592 0x77 
#define N2160x3648 0x78 
#define N2736x3648 0x79 


#define XPAL720x576		0x03	// (D1)
#define XPAL352x288		0x04	// (CIF)
#define XPAL176x144		0x05	// (QCIF)
#define XPAL640x480		0xC0	// (VGA)
#define XPAL320x240		0xC6	// (QVGA)
#define XPAL160x112		0xC7	// (QQVGA)


#define P320x192		0x84
#define P384x288		0x85
#define P640x368		0x86
#define P704x576		0x87
#define P768x576		0x88

enum CODEC_TYPES			/** CODEC Types */
{ 
	XVIDCODEC,				///< #0# - XVID - using XVIDCODEC
	WISCODEC,				///< #1# - WIS - using WISCODEC
	P51CODEC,				///< #2# - PCI5100 - using P51CODEC
	IPPCODEC,				///< #3# - IPPCODEC - using IPPCODEC
	MJPEGCODEC,
	IH264CODEC
};

enum FILE_WRITER_TYPES		/** File writer types */
{ 
	FRAW,					///< #0# - Record by *.Raw File - using FRAW
	FAVI,					///< #1# - Record by *.Avi File - using FAVI
	FRAW2					///< #1# - Record by *.Raw File with *.idx file - using FRAW2
};

enum DRAWER_TYPES			/** Drawer interface types */
{ 
	DGDI,					///< Request to use Windows GDI for draw
	DXDRAW					///< Request to use Direct Draw for draw
};

enum SERVER_DEVICE_TYPE	/** Device Type */
{
	Type_None,				///< None type
	Type_StandAlong,		///< Stand along
	Type_RackMount,			///< Rack Mount
	Type_Blade				///< Blade
};
// callback function type define
typedef void ( CALLBACK * CONTROL_DATA_CALLBACK		)( DWORD UserParam, DWORD dwDataType, BYTE* buf, DWORD len );
typedef void ( CALLBACK * RS232_DATA_CALLBACK		)( DWORD UserParam, BYTE* buf, DWORD len );
typedef void ( CALLBACK * TIME_CODE_CALLBACK			)( DWORD UserParam, DWORD TimeCode );
typedef void ( CALLBACK * VIDEO_LOSS_CALLBACK		)( DWORD UserParam );
typedef void ( CALLBACK * VIDEO_RECOVERY_CALLBACK	)( DWORD UserParam );
typedef void ( CALLBACK * VIDEO_LOSS_CALLBACK2 )( DWORD UserParam, unsigned char VideoLossFlag );
typedef void ( CALLBACK * VIDEO_RECOVERY_CALLBACK2 )( DWORD UserParam, unsigned char VideoRecoveryFlag );
typedef void ( CALLBACK * NETWORK_LOSS_CALLBACK		)( DWORD UserParam );
typedef void ( CALLBACK * MOTION_DETECTION_CALLBACK	)( DWORD UserParam, bool Motion1, bool Motion2, bool Motion3 );
typedef void ( CALLBACK * MOTION_DETECTION_CALLBACK2	)( DWORD UserParam, unsigned char Motion, unsigned char PIR);
typedef void ( CALLBACK * QUAD_MOTION_DETECTION_CALLBACK	)( DWORD UserParam, bool Motion1, bool Motion2, bool Motion3, bool Motion4 );
typedef void ( CALLBACK * DI_CALLBACK				)( DWORD UserParam, bool DI1, bool DI2 );
typedef void ( CALLBACK * DI_CALLBACK_FOR_4100		)( DWORD UserParam, bool DI1, bool DI2, bool DI3, bool DI4 );
typedef void ( CALLBACK * RAW_DATA_CALLBACK			)( DWORD UserParam, DWORD dwdataType, BYTE* buf, DWORD len );
//typedef void ( CALLBACK * IMAGE_CALLBACK				)( DWORD UserParam, BYTE* buf, DWORD len, DWORD dwWidth, DWORD dwHeight );
typedef void ( CALLBACK * IMAGE_CALLBACK2			)( DWORD UserParam, LPVOID pHeader, BYTE* buf, DWORD len, DWORD dwWidth, DWORD dwHeight );
typedef void ( CALLBACK * IMAGE_CALLBACK3			)( DWORD UserParam, LPVOID b2, LPBITMAPINFO bmpinfo, LPBYTE buf, DWORD len, DWORD dwWidth, DWORD dwHeight );
typedef void ( CALLBACK * AFTER_RENDER_CALLBACK		)( DWORD UserParam );
typedef void ( CALLBACK * AFTER_RENDER_CALLBACK_EX	)( DWORD UserParam, HDC hdc );
typedef void ( CALLBACK * RESOLUTION_CHANGE_CALLBACK	)( DWORD UserParam, int nResolution );
typedef void ( CALLBACK * QUAD_VIDEO_LOSS_CALLBACK		)( DWORD UserParam, bool bR1Videoloss, bool bR2Videoloss, bool bR3Videoloss, bool bR4Videoloss );
typedef void ( CALLBACK * FILE_PLAY_COMPLETE_CALLBACK )( DWORD UserParam );
typedef void ( CALLBACK * FIRST_B2_CALLBACK )( DWORD UserParam , BYTE* buf, DWORD len );
typedef void ( CALLBACK * VIDEO_STREAM_CONTROL_CALLBACK	)( DWORD UserParam, DWORD MsgType, BYTE* buf, DWORD len );
typedef void ( CALLBACK * QUAD_VIDEO_RECOVERY_CALLBACK	)( DWORD UserParam, bool bR1VideoRecovery, bool bR2VideoRecovery, bool bR3VideoRecovery, bool bR4VideoRecovery );

//typedef struct structural_DI_EX_CALLBACK_DATA
//{
//	int DIStatus[32]; 
//}DI_EX_CALLBACK_DATA;
//
//typedef void ( CALLBACK *DI_CALLBACK_EX	)( DWORD UserParam, DI_EX_CALLBACK_DATA di );

typedef void ( CALLBACK *TIME_CODE_CALLBACK_EX		)( DWORD UserParam, timeval TimeCodeIncludeMicroseconds );


typedef struct structural_MEDIA_CONNECTION_CONFIG
{		
	int	ContactType;

	unsigned char	ChannelNumber;	// For URL Command CHANNEL tag, when set it to 0, URL command won't bring CHANNEL tag, or the URL command will bring CHANNEL=ChannelNumber tag  )
	unsigned char	TCPVideoStreamID;	// 0 based to specify video track, value 0 to 255 for 1 to 256 video track
	unsigned char	RTPVideoTrackNumber;	// set it to 0, ARTP will use 1st video track,  1 to 255 is for specify video track
	unsigned char	RTPAudioTrackNumber;	// set it to 0, ARTP will use 1st audio track,  1 to 255 is for specify audio track

	char			UniCastIP[16];
	char			MultiCastIP[16];
	char			PlayFileName[256];
	char			UserID[64];
	char			Password[64];
	unsigned long	RegisterPort;
	unsigned long	StreamingPort;
	unsigned long	ControlPort;
	unsigned long	MultiCastPort;
	unsigned long	SearchPortC2S;
	unsigned long	SearchPortS2C;
	unsigned long	HTTPPort;
	unsigned long	RTSPPort;
	unsigned long	Reserved1;
	unsigned long	Reserved2;

	unsigned short	ConnectTimeOut;
	unsigned short	EncryptionType;
}MEDIA_CONNECTION_CONFIG;

typedef struct structural_MEDIA_CONNECTION_CONFIG2
{		
	int	ContactType;

	unsigned char	ChannelNumber;	// For URL Command CHANNEL tag, when set it to 0, URL command won't bring CHANNEL tag, or the URL command will bring CHANNEL=ChannelNumber tag  )
	unsigned char	TCPVideoStreamID;	// 0 based to specify video track, value 0 to 255 for 1 to 256 video track
	unsigned char	RTPVideoTrackNumber;	// set it to 0, ARTP will use 1st video track,  1 to 255 is for specify video track
	unsigned char	RTPAudioTrackNumber;	// set it to 0, ARTP will use 1st audio track,  1 to 255 is for specify audio track

	char			UniCastIP[256];
	char			MultiCastIP[16];
	char			PlayFileName[256];
	char			UserID[64];
	char			Password[64];
	unsigned long	RegisterPort;
	unsigned long	StreamingPort;
	unsigned long	ControlPort;
	unsigned long	MultiCastPort;
	unsigned long	SearchPortC2S;
	unsigned long	SearchPortS2C;
	unsigned long	HTTPPort;
	unsigned long	RTSPPort;
	unsigned long	Reserved1;
	unsigned long	Reserved2;

	unsigned short	ConnectTimeOut;
	unsigned short	EncryptionType;
}MEDIA_CONNECTION_CONFIG2;

typedef struct structural_MEDIA_CONNECTION_CONFIG3
{		
	int	ContactType;

	unsigned char	ChannelNumber;	// For URL Command CHANNEL tag, when set it to 0, URL command won't bring CHANNEL tag, or the URL command will bring CHANNEL=ChannelNumber tag  )
	unsigned char	TCPVideoStreamID;	// 0 based to specify video track, value 0 to 255 for 1 to 256 video track
	unsigned char	RTPVideoTrackNumber;	// set it to 0, ARTP will use 1st video track,  1 to 255 is for specify video track
	unsigned char	RTPAudioTrackNumber;	// set it to 0, ARTP will use 1st audio track,  1 to 255 is for specify audio track

	char			UniCastIP[256];
	char			MultiCastIP[16];
	char			PlayFileName[1024];
	char			UserID[256];
	char			Password[256];
	unsigned long	RegisterPort;
	unsigned long	StreamingPort;
	unsigned long	ControlPort;
	unsigned long	MultiCastPort;
	unsigned long	SearchPortC2S;
	unsigned long	SearchPortS2C;
	unsigned long	HTTPPort;
	unsigned long	RTSPPort;
	unsigned long	Reserved1;
	unsigned long	Reserved2;

	unsigned short	ConnectTimeOut;
	unsigned short	EncryptionType;
}MEDIA_CONNECTION_CONFIG3;

typedef struct structural_MEDIA_COMMAND
{
	DWORD dwCommandType;
	char* pCommand;
	int	  nCommandLength;
	char* pResult;
	int   nResultLength;
} MEDIA_COMMAND;

typedef struct structural_STREAMING_ENGINE_CONFIG
{
	char      szUserID[16];                     // Streaming engine login ID
	char      szUserPwd[16];                    // Streaming engine login Password
	char      szServerIP[16];                   // Streaming engine IP address
	DWORD dwStreamingPort;						// Audio/Video port number for streaming engine
	DWORD dwControlPort;						// Control port number for streaming engine
}STREAMING_ENGINE_CONFIG;

typedef struct structural_STREAMING_ENGINE_CONFIG2
{
	char      szUserID[64];                       // Streaming engine login ID
	char      szUserPwd[64];                    // Streaming engine login Password
	char      szServerIP[256];                     // Streaming engine IP address
	DWORD dwStreamingPort;                  // Audio/Video port number for streaming engine
	DWORD dwControlPort;                      // Control port number for streaming engine
}STREAMING_ENGINE_CONFIG2;

typedef struct structural_MEDIA_VIDEO_CONFIG
{
	DWORD dwTvStander;			///< 0:NTSC 1:PAL
	DWORD dwVideoResolution;	///< See the definition above
	DWORD dwBitsRate;			///< See the definition above
	DWORD dwVideoBrightness;	///< 0 ~ 100 : Low ~ High
	DWORD dwVideoContrast;		///< 0 ~ 100 : Low ~ High
	DWORD dwVideoSaturation;	///< 0 ~ 100 : Low ~ High
	DWORD dwVideoHue;			///< 0 ~ 100 : Low ~ High
	DWORD dwFps;				///< 0 ~ 30 frame pre second
} MEDIA_VIDEO_CONFIG;

typedef struct structural_MEDIA_VIDEO_CONFIG2
{
	short dwEncoder;			// 1:MPEG4 4:MPEG4 5:H264
	short dwTvStander;			// 0:NTSC 1:PAL
	short dwVideoResolution;	// See the definition above
	short dwBitsRate;			// See the definition above
	short dwQuality;			// 0 ~ 100 : Low ~ High
	short dwVideoBrightness;	// 0 ~ 100 : Low ~ High
	short dwVideoContrast;		// 0 ~ 100 : Low ~ High
	short dwVideoSaturation;	// 0 ~ 100 : Low ~ High
	short dwVideoHue;			// 0 ~ 100 : Low ~ High
	short dwFps;				// 0 ~ 30 frame pre second
} MEDIA_VIDEO_CONFIG2;

typedef struct structural_MEDIA_VIDEO_CONFIG3
{
	short dwEncoder;			// 1:MPEG4 4:MPEG4 5:H264
	short dwTvStander;			// 0:NTSC 1:PAL

	DWORD dwWidth;
	DWORD dwHeight;

	short dwBitsRate;			// See the definition above
	short dwQuality;			// 0 ~ 100 : Low ~ High
	short dwVideoBrightness;	// 0 ~ 100 : Low ~ High
	short dwVideoContrast;		// 0 ~ 100 : Low ~ High
	short dwVideoSaturation;	// 0 ~ 100 : Low ~ High
	short dwVideoHue;			// 0 ~ 100 : Low ~ High
	short dwFps;				// 0 ~ 30 frame pre second
} MEDIA_VIDEO_CONFIG3;

typedef struct structural_MEDIA_PORT_INFO /** Device port info. */
{
	unsigned long PORT_HTTP;				///< HTTP Port
	unsigned long PORT_SearchPortC2S;		///< Search Port 1
	unsigned long PORT_SearchPortS2C;		///< Search Port 2
	unsigned long PORT_Register;			///< Register Port
	unsigned long PORT_Control;				///< Control Port
	unsigned long PORT_Streaming;			///< Streaming Port
	unsigned long PORT_Multicast;			///< Multicast Port
	unsigned long PORT_RTSP;				///< RTSP Port
} MEDIA_PORT_INFO;

typedef struct structural_MEDIA_RENDER_INFO
{
	int	  DrawerInterface;		
	HWND  hWnd;
	RECT  rect;
} MEDIA_RENDER_INFO;

typedef struct structural_MEDIA_MOTION_INFO
{
	DWORD dwEnable;
	DWORD dwRangeCount;
	DWORD dwRange[3][4];
	DWORD dwSensitive[3]; ///< 0 - 100
} MEDIA_MOTION_INFO;

#define MD_REGION_SIZE	4
typedef struct structural_MEDIA_MOTION_INFO_EX
{
	DWORD dwEnable;
	DWORD dwRangeCount;
	DWORD dwRange[MD_REGION_SIZE][4];

	DWORD dwSensitive[MD_REGION_SIZE];
	DWORD dwTime[MD_REGION_SIZE];
	DWORD dwThreshold[MD_REGION_SIZE];
	DWORD bEnable[MD_REGION_SIZE];
} MEDIA_MOTION_INFO_EX;

typedef struct structural_MP4FILE_RECORD_INFO
{
	unsigned long	tBeginTime;
	unsigned long	tEndTime;
	BYTE			btTimeZone;
	DWORD			dwGOP;
	DWORD			dwFrameCount;
	ULONGLONG		FileSize;
} MP4FILE_RECORD_INFO;

typedef struct structural_NOTIFY_DI
{
	HANDLE	DIEvent;
	BYTE	DI;
}NOTIFY_DI;

typedef struct structural_NOTIFY_TIMECODE
{
	HANDLE	TimeCodeEvent;
	DWORD	dwTimeCode;
}NOTIFY_TIMECODE;

typedef struct structural_NOTIFY_RAWDATAREFRESH
{
	HANDLE	RawDataRefreshEvent;
	void*	pBuffer;
	int		nFillLength;
}NOTIFY_RAWDATA_REFRESH;

typedef struct structural_NOTIFY_VIDEOSTATUS
{
	HANDLE	VideoLossEvent;
	HANDLE	VideoRecoveryEvent;
}NOTIFY_VIDEO_STATUS;

typedef struct structural_NOTIFY_NETWORKLOSS
{
	HANDLE	NetworkLossEvent;
}NOTIFY_NETWORK_LOSS;


typedef struct structural_NOTIFY_MOTIONDETECTION
{
	HANDLE	MotionDetectionEvent;
	BYTE	MotionDetection;
}NOTIFY_MOTION_DETECTION;

typedef struct structural_NOTIFY_IMAGE_REFRESH
{
	HANDLE	ImageRefreshEvent;
	void*	pImage;
	int		nFillLength;
}NOTIFY_IMAGE_REFRESH;

typedef struct structural_NOTIFY_AFTER_RENDER
{
	HANDLE	AfterRenderEvent;
}NOTIFY_AFTER_RENDER;

typedef struct structural_NOTIFY_RESOLUTION_CHANGE
{
	HANDLE	ResolutionChangeEvent;
	int		nResolution;
}NOTIFY_RESOLUTION_CHANGE;

typedef struct structural_NOTIFY_RS232DATA_REFRESH
{
	HANDLE	RS232DataRefreshEvent;
	void*	pBuffer;
	int		nFillLength;
}NOTIFY_RS232DATA_REFRESH;

typedef struct {
	int		iCardID;
	int		iPciSlot;
	int		iChannelID;
	int		iInstanceID;
	char    Version[32];
} CAP_SEARCH_CAPCARD;

typedef struct structural_MEDIA_PTZ_PROTOCOL
{
	int nSourceType;		// [in]Specify the source type is  inside resource or a PTZ protocol file
	char szVender[32];		// [in]Vender Name
	char szProtocol[32];	// [in]Protocol Name
	char szProtocolFileName[512]; // [in]Specify the PTZ protocol file name
	DWORD dwAddressID;		// Address ID
} MEDIA_PTZ_PROTOCOL;

typedef struct _VIDEO_TRANSFER_CONFIG
{
	bool bTransfer;
	int nVideoOutType;
	int nBitRate;
	int nFpsNum;

	bool bReSize;
	int nResolution;
}VIDEO_TRANSFORM_CONFIG;

//typedef struct _RAW_TIMEINFO
//{
//	DWORD dwSize;
//	DWORD dwBeginTime;
//	DWORD dwEndTime;
//	DWORD dwTimeZone;
//	char nTimeComplementarity;
//}RAW_TIMEINFO;
//
//typedef struct _RAW_TIMEINFO2
//{
//	DWORD dwSize;
//
//	__int64 nBeginTimeSec;	// UTC sec
//	__int64 nEndTimeSec;	// UTC sec
//
//	short sBeginTimeMilliSec;	// UTC millisec
//	short sEndTimeMilliSec;	// UTC millisec
//
//	DWORD dwTimeZone;
//	char nTimeComplementarity;
//}RAW_TIMEINFO2;

DLL_API void KGetVersion( char* VersionInfo );
DLL_API HANDLE KOpenInterface();
DLL_API bool KSetMediaConfig( HANDLE h, MEDIA_CONNECTION_CONFIG* MediaConfig );
DLL_API bool KSetMediaConfig2( HANDLE h, MEDIA_CONNECTION_CONFIG2* MediaConfig );
DLL_API bool KSetMediaConfig3( HANDLE h, MEDIA_CONNECTION_CONFIG3* MediaConfig );

// For Play Multiple Files
//DLL_API bool KSetMultipleMediaConfig( HANDLE h, MEDIA_CONNECTION_CONFIG* pMediaconfig );
//DLL_API bool KSetMultipleMediaConfig2( HANDLE h, MEDIA_CONNECTION_CONFIG2 * pMediaconfig );
//DLL_API bool KAddMultipleMedia( HANDLE h, DWORD Nth, char* strFileName);
//DLL_API void KRemoveMultipleMedia( HANDLE h, DWORD Nth);
//DLL_API void KClearAllMultipleMedia( HANDLE h );
//DLL_API void KGetNthBeginTimeFromMultipleMedia( HANDLE h, DWORD Nth,  DWORD& dwBeginTime );
//DLL_API void KGetNthEndTimeFromMultipleMedia( HANDLE h, DWORD Nth, DWORD& dwEndTime );
//DLL_API void KGetTotalIFramesOfMultipleMedia( HANDLE h, DWORD& dwIFramesNumber );
//DLL_API void KGetCurrentReadingFileIDFromMultipleMedia( HANDLE h, DWORD& Nth);
//DLL_API void KGetCurrentReadingAbsTimeFromMultipleMedia( HANDLE h, DWORD& dwABSTime);

DLL_API bool KGetVideoConfig( HANDLE h, MEDIA_VIDEO_CONFIG* VideoConfig );
DLL_API bool KGetVideoConfig2( HANDLE h, MEDIA_VIDEO_CONFIG2* VideoConfig );
DLL_API bool KGetVideoConfig3( HANDLE h, MEDIA_VIDEO_CONFIG3* VideoConfig );
DLL_API bool KSetVideoConfig( HANDLE h, MEDIA_VIDEO_CONFIG* VideoConfig );
DLL_API bool KSetVideoConfig2( HANDLE h, MEDIA_VIDEO_CONFIG2* VideoConfig );
DLL_API bool KConnect( HANDLE h );
DLL_API bool KStartStreaming( HANDLE h );
DLL_API void KStopStreaming( HANDLE h );
DLL_API void KPlay( HANDLE h );
DLL_API void KSEStartStreaming( HANDLE h );
DLL_API void KPause( HANDLE h );
DLL_API void KSetPauseAfterCompleted( HANDLE h, bool flg );
DLL_API void KStop( HANDLE h );
DLL_API void KDisconnect( HANDLE h );
DLL_API void KSetRenderInfo( HANDLE h, MEDIA_RENDER_INFO* RenderInfo );
DLL_API void KSetMotionInfo( HANDLE h, MEDIA_MOTION_INFO* MotionInfo );
DLL_API void KGetMotionInfo( HANDLE h, MEDIA_MOTION_INFO* MotionInfo );
DLL_API void KCloseInterface( HANDLE h );
DLL_API void KSetVolume( HANDLE h, int nLeftVolume, int nRightVolume );
DLL_API void KGetVolume( HANDLE h, int& nLeftVolume, int& nRightVolume );
DLL_API void KSetMute( HANDLE h, bool bMute );
DLL_API void KSetDebugMessageLevel( HANDLE h, int nDebugLevel );
DLL_API void KSetDecodeIFrameOnly( HANDLE h, bool bDecodeIOnly );
DLL_API bool KGetAudioToken( HANDLE h, char* pholder );
DLL_API void KFreeAudioToken( HANDLE h );
DLL_API bool KStartAudioTransfer( HANDLE h );
DLL_API void KStopAudioTransfer( HANDLE h );
DLL_API void KSetRawDataCallback( HANDLE h, DWORD UserParam, RAW_DATA_CALLBACK fnRawDataCallback );
DLL_API void KEnableFullScreen( HANDLE h, bool bFullScreen );
DLL_API DWORD KNotifyFullScreenWindow( HANDLE h, UINT message, WPARAM wParam, LPARAM lParam );
DLL_API void KEnableStretchMode( HANDLE h, bool bStretchMode );
DLL_API void KEnableRender( HANDLE h, bool bEnableRender );
DLL_API void KEnableDecoder( HANDLE h, bool bEnableDecorder );
//DLL_API void KSetImageCallback( HANDLE h, DWORD UserParam, IMAGE_CALLBACK fnImageCallback );
DLL_API void KSetImageCallback2( HANDLE h, DWORD UserParam, IMAGE_CALLBACK2 fnImageCallback );
DLL_API void KSetImageCallback3( HANDLE h, DWORD UserParam, IMAGE_CALLBACK3 fnImageCallback );
DLL_API void KSetAfterRenderCallback( HANDLE h, DWORD UserParam, AFTER_RENDER_CALLBACK fnAfterRenderCallback );
DLL_API void KSetAfterRenderCallbackEx( HANDLE h, DWORD UserParam, AFTER_RENDER_CALLBACK_EX fnAfterRenderCallback );
DLL_API void KSetResolutionChangeCallback( HANDLE h, DWORD UserParam, RESOLUTION_CHANGE_CALLBACK fnResolutionChangeCallback );
DLL_API bool KSendCommandToStreamingEngine( HANDLE h, char* URLCommand );
DLL_API bool KSendCommandToSE( HANDLE h,  char* URLCommand, DWORD dwLen, char* ResultBuffer, DWORD& ResultBufferLen );
DLL_API void KSetCODECType( HANDLE h, int nType, int nChannel );
DLL_API bool KReadAudioFromPCI5100( HANDLE h, BYTE* pBuffer, LONG& lBufferLen );
DLL_API bool KPlayTheAudioFromPCI5100ToPCSoundDevice( HANDLE h, bool bPlay );
DLL_API void KSetFileWriterType( HANDLE h, int nType );
DLL_API bool KStartRecord( HANDLE h, char* FileName );
DLL_API void KStopRecord( HANDLE h, MP4FILE_RECORD_INFO* mri );
DLL_API void KSetPrerecordTime( HANDLE h, int nInSecond );
DLL_API int KGetTCPTypeByHTTP( HANDLE h, char* HTTPIP, unsigned long HTTPPort, char* UID, char* PWD, unsigned int ChannelNO = 0 );
DLL_API int KGetDeviceTypeByHTTP( HANDLE h, char* HTTPIP, unsigned long HTTPPort, char* UID, char* PWD );
DLL_API int KGetNumberOfChannelByHTTP( HANDLE h, char* HTTPIP, unsigned long HTTPPort, char* UID, char* PWD );
DLL_API bool KGetPortInfoByHTTP( HANDLE h, MEDIA_PORT_INFO* mri, char* HTTPIP, unsigned long HTTPPort, char* UID, char* PWD, unsigned int ChannelNO = 0 );
DLL_API void KSetTCPType( HANDLE h, int Type );
DLL_API void KSendDO( HANDLE h, BYTE bDOData );
DLL_API void KSendRS232Setting( HANDLE h, BYTE c81, BYTE dwBaudRate, int nComNumber );
DLL_API void KSendRS232Command( HANDLE h, BYTE* cmd, DWORD len );
DLL_API void KSendPTZCommand( HANDLE h, BYTE* cmd, DWORD len );
DLL_API void KSetCurrentPosition( HANDLE h, DWORD dwPosition );
DLL_API void KSetCurrentTime( HANDLE h, DWORD dwTimecode );
DLL_API void KSetCurrentTimeUTC( HANDLE h, DWORD dwTimecode );

DLL_API DWORD KGetCurrentTime( HANDLE h );
DLL_API void KSetBrightness( HANDLE h, DWORD dwBrightness );
DLL_API void KSetContrast( HANDLE h, DWORD dwContrast );
DLL_API void KSetSaturation( HANDLE h, DWORD dwSaturation );
DLL_API void KSetHue( HANDLE h, DWORD dwHue );
DLL_API void KSetBitRate( HANDLE h, DWORD dwBitRate );
DLL_API void KSetResolution( HANDLE h, DWORD dwResolution );
DLL_API void KSetFPS( HANDLE h, DWORD dwFPS );
DLL_API void KSetVariableFPS( HANDLE h, DWORD dwVariableFPS );
DLL_API void KSaveReboot( HANDLE h );
DLL_API void KSendControlCommand( HANDLE h, DWORD dwCmdType, BYTE* ControlCommand, DWORD dwLen );
DLL_API void KSendURLCommand( HANDLE h, char* URLCommand, DWORD dwLen, char* ResultBuffer, DWORD& ResultBufferLen );
DLL_API void KSetTimeCodeCallback( HANDLE h, DWORD UserParam, TIME_CODE_CALLBACK fnTimeCodeCallback );
DLL_API void KSetVideoLossCallback( HANDLE h, DWORD UserParam, VIDEO_LOSS_CALLBACK fnVideoLossCallback );
DLL_API void KSetVideoRecoveryCallback( HANDLE h, DWORD UserParam, VIDEO_RECOVERY_CALLBACK fnVideoRecoveryCallback );
DLL_API void KSetNetworkLossCallback( HANDLE h, DWORD UserParam, NETWORK_LOSS_CALLBACK fnNetworkLossCallback );
DLL_API void KSetMotionDetectionCallback( HANDLE h, DWORD UserParam, MOTION_DETECTION_CALLBACK fnMotionDetectionCallback );
DLL_API void KSetMotionDetectionCallback2( HANDLE h, DWORD UserParam, MOTION_DETECTION_CALLBACK2 fnMotionDetectionCallback );
DLL_API void KSetVideoLossCallback2( HANDLE h, DWORD UserParam, VIDEO_LOSS_CALLBACK2 fnVideoLossCallback );
DLL_API void KSetVideoRecoveryCallback2( HANDLE h, DWORD UserParam, VIDEO_RECOVERY_CALLBACK2 fnVideoRecoveryCallback );
DLL_API void KSetQuadMotionDetectionCallback( HANDLE h, DWORD UserParam, QUAD_MOTION_DETECTION_CALLBACK fnQuadMotionDetectionCallback );
DLL_API void KSetDIDefaultValue( HANDLE h, BYTE bDefault );
DLL_API void KSetDICallback( HANDLE h, DWORD UserParam, DI_CALLBACK fnDICallback );
DLL_API void KSetRS232DataCallback( HANDLE h, DWORD UserParam, RS232_DATA_CALLBACK fnRS232Callback );
DLL_API void KSetControlDataCallback( HANDLE h, DWORD UserParam, CONTROL_DATA_CALLBACK fnControlCallback );
DLL_API void KSetPlayRate( HANDLE h, int nRate );
DLL_API void KSetPlayDirection( HANDLE h, bool bForward );
DLL_API void KStepPrevFrame( HANDLE h );
DLL_API void KStepNextFrame( HANDLE h );
//DLL_API void KSetEvent_DI( HANDLE h, NOTIFY_DI* nDI );
//DLL_API void KSetEvent_TimeCode( HANDLE h, NOTIFY_TIMECODE* nTimeCode );
//DLL_API void KSetEvent_RawDataRefresh( HANDLE h, NOTIFY_RAWDATA_REFRESH* nRawData );
//DLL_API void KSetEvent_VideoStatus( HANDLE h, NOTIFY_VIDEO_STATUS* nVideoStatus );
//DLL_API void KSetEvent_NetworkLoss( HANDLE h, NOTIFY_NETWORK_LOSS* nNetworkLoss );
DLL_API void KSetEvent_MotionDetection( HANDLE h, NOTIFY_MOTION_DETECTION* nMotionDetection );
DLL_API void KSetEvent_ImageRefresh( HANDLE h, NOTIFY_IMAGE_REFRESH* nImageRefersh );
//DLL_API void KSetEvent_AfterRender( HANDLE h, NOTIFY_AFTER_RENDER* nAfterRender );
//DLL_API void KSetEvent_ResolutionChange( HANDLE h, NOTIFY_RESOLUTION_CHANGE* nResolutionChange );
//DLL_API void KSetEvent_RS232DataRefresh( HANDLE h, NOTIFY_RS232DATA_REFRESH* nRS232Data );

DLL_API void KReverseImageLeftToRight( HANDLE h, bool bEnableLeftToRight );
DLL_API void KReverseImageUpToDown( HANDLE h, bool bEnableUpToDown );

DLL_API int KGetVideoFrameCount( HANDLE h );
DLL_API LPBITMAPINFO KGetLastFrame( HANDLE h );

DLL_API void KGetBeginTime( HANDLE h, DWORD& dwBeginTime );
DLL_API void KGetEndTime( HANDLE h, DWORD& dwEndTime );

//DLL_API long KGetRawTimeZoneSec (HANDLE h);
//DLL_API long KGetRawFixTimeZoneSec (HANDLE h);

//DLL_API BOOL KGetRawTimeInfo( HANDLE h, RAW_TIMEINFO * pRawTimeInfo);
//DLL_API BOOL KGetRawTimeInfo2( HANDLE h, RAW_TIMEINFO2 * pRawTimeInfo);

typedef struct _RAW_FILEINFO2
{
	__int64 iBeginTimeSec;	// UTC sec
	__int64 iEndTimeSec;	// UTC sec

	long lBeginTimeBias;
	long lBeginDaylightBias;

	long lEndTimeBias;
	long lEndDaylightBias;

	unsigned long ulGOPCount;
	__int64 iFileSize;

	BYTE Reserve[32];
}RAW_FILEINFO2;

typedef struct _RAW_FILEINFO3
{
	__int64 iBeginTimeSec;	// UTC sec
	__int64 iEndTimeSec;	// UTC sec

	struct timeval BeginTimeTS;
	struct timeval EndTimeTS;

	long lBeginTimeBias;
	long lBeginDaylightBias;

	long lEndTimeBias;
	long lEndDaylightBias;

	unsigned long ulGOPCount;
	__int64 iFileSize;


}RAW_FILEINFO3;

DLL_API bool KGetRawFileInfo2( HANDLE h, RAW_FILEINFO2 * pRecordInfo );
DLL_API bool KGetRawFileInfo3( HANDLE h, RAW_FILEINFO3 * pRecordInfo );
DLL_API __int64 KGetCurrentFilePos( HANDLE h );

DLL_API BYTE KGetDIDefaultValueByHTTP( HANDLE h, char* IP, unsigned long HTTPPort, char* UID, char* PWD );
DLL_API DWORD KGetTotalReceiveSize( HANDLE h );
DLL_API DWORD KGetTotalReceiveVideoFrameCount( HANDLE h );
DLL_API DWORD KGetTotalReceiveAudioFrameCount( HANDLE h );
DLL_API bool KGetCameraName( HANDLE h, char* pCameraNameBuffer, int nBufferSize );
//DLL_API void KResetMediaConfig( HANDLE h );
DLL_API void KSetDrawerType( HANDLE h, int nType );
DLL_API DWORD KGetLastError( HANDLE h );
DLL_API void KSetSequenceHeaderChecker( HANDLE h, bool bEnable, DWORD dwTimerInSec );
DLL_API bool KSetStreamingEngineMediaConfig( HANDLE h, STREAMING_ENGINE_CONFIG* StreamingConfig, MEDIA_CONNECTION_CONFIG* Mediaconfig );
DLL_API bool KSetStreamingEngineMediaConfig2( HANDLE h, STREAMING_ENGINE_CONFIG2 * StreamingConfig, MEDIA_CONNECTION_CONFIG2* Mediaconfig );
DLL_API void KSendCommand( HANDLE h, MEDIA_COMMAND* mc );
DLL_API BYTE KGetDIOStatusByHTTP( HANDLE h, char* IP, unsigned long HTTPPort, char* UID, char* PWD );
DLL_API BYTE KGetDIOStatusByHTTPEx( HANDLE h, char* IP, unsigned long HTTPPort, unsigned long nChannel, char* UID, char* PWD );

//DLL_API void KSetFilePlayCompeleteCallback( HANDLE h, DWORD UserParam, FILE_PLAY_COMPLETE_CALLBACK fnFilePlayCompeleteCallback );
DLL_API void KSetFilePlayCompleteCallback( HANDLE h, DWORD UserParam, FILE_PLAY_COMPLETE_CALLBACK fnFilePlayCompeleteCallback );

DLL_API int KQuadGetDisplayMode( HANDLE h );
DLL_API void KSetTextOut(HANDLE h, int nIndex, int nX, int nY, WCHAR* Text, int nTextLen, bool bBold, bool bItalic, bool bUnderLine, const WCHAR* pFontName, int nFontSize, COLORREF color, int nBKMode, COLORREF BKcolor);
DLL_API bool KQuadSetDisplayMode( HANDLE h,  int nMode );
DLL_API BYTE KQuadGetOSDEnable( HANDLE h );
DLL_API bool KQuadSetOSDEnable( HANDLE h,  BYTE btEnable );
DLL_API BYTE KQuadGetMotionDetectionEnable( HANDLE h );
DLL_API bool KQuadSetMotionDetectionEnable( HANDLE h, BYTE btEnable );
DLL_API int KQuadGetMotionSensitive( HANDLE h, int nChannel );
DLL_API bool KQuadSetMotionSensitive( HANDLE h, int nChannel, int nSensitive );
DLL_API int KQuadGetTitleName( HANDLE h, int nChannel, char* pName8Bytes );
DLL_API bool KQuadSetTitleName( HANDLE h, int nChannel, char* pName8Bytes );
DLL_API int KQuadGetBrightness( HANDLE h, int nChannel );
DLL_API bool KQuadSetBrightness( HANDLE h, int nChannel, int nBrightness );
DLL_API int KQuadGetContrast( HANDLE h, int nChannel );
DLL_API bool KQuadSetContrast( HANDLE h, int nChannel, int nContrast );
DLL_API int KQuadGetSaturation( HANDLE h, int nChannel );
DLL_API bool KQuadSetSaturation( HANDLE h, int nChannel, int nSaturation );
DLL_API int KQuadGetHue( HANDLE h, int nChannel );
DLL_API bool KQuadSetHue( HANDLE h, int nChannel, int nHue );
DLL_API bool KSendAudio( HANDLE h, BYTE* pAudioBuffer, int nLen );
DLL_API bool KSendAudioToSE( HANDLE h, BYTE* pAudioBuffer, int nLen );
DLL_API bool KGetNextIFrame( HANDLE h);
DLL_API bool KGetPrevIFrame( HANDLE h);
DLL_API int KGetFrameRateMode( HANDLE h, char* IP, unsigned long HTTPPort, char* UID, char* PWD, unsigned int ChannelNO = 0 );
DLL_API bool KSendURLCommandToDevice(HANDLE h, char* IP, unsigned long HTTPPort, char* URLCommand, DWORD dwURLCommandLen, char* ResultBuffer, DWORD& dwResultBufferLen );
DLL_API void KPCI4100SetDICallback( HANDLE h, DWORD UserParam, DI_CALLBACK_FOR_4100 fnDICallback );
DLL_API int KPCI4100GetCardCount( HANDLE h );
DLL_API int KPCI4100Get4100ChannelCount( HANDLE h );
DLL_API int KPCI4100SearchCapCard( HANDLE h, CAP_SEARCH_CAPCARD * pSearchCard, DWORD &dwTotalNo);
DLL_API int KPCI4100SearchCapChannel( HANDLE h, CAP_SEARCH_CAPCARD * pSearchCard, DWORD &dwTotalNo);
DLL_API bool KPCI4100GetChannelHSync( HANDLE h );
DLL_API void KSetQuadVideoLossCallback( HANDLE h, DWORD UserParam, QUAD_VIDEO_LOSS_CALLBACK fnQuadVideolossCallback );
DLL_API void KSetTargetDeviceType( HANDLE h, DeviceType type);
DLL_API void KSetTargetCameraIsQuad( HANDLE h, bool bIsQuad );
DLL_API bool KEnablePTZProtocol(HANDLE h, bool bEnable);

DLL_API bool KPTZLoadProtocol(HANDLE h, MEDIA_PTZ_PROTOCOL* pMPP);
DLL_API bool KPTZUnloadProtocol(HANDLE h);
DLL_API bool KPTZMove(HANDLE h, int nAddrID, int nSpeed, PTZ_MOVE_OPERATION PTZMoveOP);
DLL_API bool KPTZZoom(HANDLE h, int nAddrID, int nSpeed, PTZ_ZOOM_OPERATION PTZZoomOP);
DLL_API bool KPTZSetZoomSpeed( HANDLE h, int nAddrID, int nSpeed );
DLL_API bool KPTZPreset(HANDLE h, int nAddrID, int nPresetPos, PTZ_RESEST_OPERATION PTZPresetOP);
DLL_API bool KPTZOSD(HANDLE h, int nAddrID,  PTZ_OSD_OPERATION PTZOSDOP);
DLL_API bool KPTZBLC(HANDLE h, int nAddrID,  PTZ_BLC_OPERATION PTZBLCOP);
DLL_API bool KPTZDayNight(HANDLE h, int nAddrID,  PTZ_DN_OPERATION PTZDNOP);
DLL_API bool KPTZFocus(HANDLE h, int nAddrID,  PTZ_FOCUS_OPERATION PTZFocusOP);
DLL_API bool KPTZIris(HANDLE h, int nAddrID,  int nParam1, PTZ_IRIS_OPERATION PTZIrisOP);
DLL_API bool KPTZEnumerateProtocol(HANDLE h, char* pVender, char* pProtocol, DWORD& dwLen);
DLL_API bool KPTZEnumerateVender(HANDLE h, char* pVender, DWORD& dwLen);
DLL_API bool KPTZEnumerateFunctions(HANDLE h, char* pFunctions, DWORD& dwLen);
DLL_API bool KPTZGetCommand(HANDLE h, char* pPTZCmd, int nAddrID, int nParam1, int nParam2, BYTE* bCmd, DWORD& dwLen);
DLL_API bool KStartDecodeMode( HANDLE h );
DLL_API bool KDecodeFrame(HANDLE h, BYTE* pData, int nLen, int nRawDataType );
DLL_API void KStopDecodeMode( HANDLE h );
DLL_API void KDigitalPTZEnable( HANDLE h, bool bEnableEPTFunction );
DLL_API void KDigitalPTZTo( HANDLE h, int nXSrc, int nYSrc, int nWidth, int nHeight );
DLL_API void KMirrorImage( HANDLE h, bool bMirror );
DLL_API void KFlipImage( HANDLE h, bool bFlip );
DLL_API void KEnableJitterLessMode( HANDLE h, bool bEnable );

//DLL_API void KSetDICallbackEx( HANDLE h, DWORD UserParam, DI_CALLBACK_EX fnDIExCallback );

DLL_API void KSetTimeCodeCallbackEx( HANDLE h, DWORD UserParam, TIME_CODE_CALLBACK_EX fnTimeCodeCallbackEx );
DLL_API void KEnablePrivacyMask( HANDLE h, bool bEnable, RECT r1, RECT r2, RECT r3, BYTE btColor_R, BYTE btColor_G, BYTE btColor_B );
DLL_API bool KPTZGetAbsPTZCommand( HANDLE h, char* pPTZCmd, int iParam1, int iParam2, bool bPanCounterClock, float fPanDegree, float fTiltDegree, float fZoomRatio, BYTE* pCommand, DWORD& dwCommandLen );
DLL_API bool KPTZGetAbsPTZCommandByUnit( HANDLE h, char* pPTZCmd, int iParam1, int iParam2, bool bPanCounterClock, int iPanUnit, int iTiltUnit, int iZoomUnit, BYTE* pCommand, DWORD& dwCommandLen );
DLL_API void KPTZUnitToDegree( HANDLE h, int iPanUnit, int iTiltUnit, int iZoomUnit, float& fPanDegree, float& fTiltDegree, float& fZoomRatio );
DLL_API void KPTZDegreeToUnit( HANDLE h, float fPanDegree, float fTiltDegree, float fZoomRatio, int& iPanUnit, int& iTiltUnit, int& iZoomUnit );
DLL_API bool KPTZGetUnitFromBuffer( HANDLE h, BYTE* pDataBufferFromRS232CallBack, DWORD dwLengthOfBuffer, int& iPanUnit, int& iTiltUnit, int& iZoomUnit );
DLL_API bool KPTZGetRequestAbsPTZCommand(HANDLE h, int iParam1,BYTE* pCommand,DWORD& dwCommandLen);
DLL_API void KSetFirstB2Callback( HANDLE h, DWORD UserParam, FIRST_B2_CALLBACK fnFirstB2Callback );
DLL_API void KSetAutoDropFrameByCPUPerformance( HANDLE h, bool bEnable = false, DWORD dwCPUPerformance = 100 );
DLL_API void KDropNextPFrameTillIFrame( HANDLE h );

DLL_API void KEnableLocalTime( HANDLE h, bool bEnable );
DLL_API void KEnableDaylightTime( HANDLE h, bool bEnable );
//DLL_API void KReplaceTimeCodeByLocalTime( HANDLE h, bool bReplace );

DLL_API void KSetSmoothFastPlayback( HANDLE h, bool bIsSmoothFastPlayback );
DLL_API void KSetMotionInfoEx( HANDLE h, MEDIA_MOTION_INFO_EX* MotionInfo );
DLL_API void KGetMotionInfoEx( HANDLE h, MEDIA_MOTION_INFO_EX* MotionInfo );
DLL_API void KSetVideoTransformConfig( HANDLE h, VIDEO_TRANSFORM_CONFIG * pVTC );
DLL_API void KSetVideoStreamControlCallback( HANDLE h, DWORD UserParam, VIDEO_STREAM_CONTROL_CALLBACK fnVideoStreamControlCallback );
DLL_API void KSetQuadVideoRecoveryCallback( HANDLE h, DWORD UserParam, QUAD_VIDEO_RECOVERY_CALLBACK fnQuadVideoRecoveryCallback );
DLL_API void KEnableDisplayTime( HANDLE h, bool bEnable);
DLL_API void KSetOSDText (HANDLE h, int index, bool state, int rr, int gg, int bb, int transparent, int alignment, char *DateFormat, char *UserDefineStr);
DLL_API bool KShowLastFrame( HANDLE h );

enum
{
	EVEMT_TYPE_NONE = 0,
	EVEMT_TYPE_NETWORKLOSS = EVEMT_TYPE_NONE,
	EVEMT_TYPE_MOTION,
	EVEMT_TYPE_PIR,
	EVEMT_TYPE_DI,

	EVEMT_TYPE_VIDEOLOSS,
	EVEMT_TYPE_VIDEORECOVERY,
};

enum
{
	RECORD_FILE_STATUS_NONE = 0,
	RECORD_FILE_STATUS_CREATE_FAIL,
	RECORD_FILE_STATUS_CREATE,
	RECORD_FILE_STATUS_COMPLETE,
	
};

typedef void ( CALLBACK *RECORDING_STATUS_CALLBACK )( DWORD UserParam,
	int EventType, unsigned char uEventIndex, BYTE * buf, DWORD len,
	int FileStatus, char * Fullfilename, LPVOID Mri);

DLL_API void KSetRecordConfig( HANDLE h,
	unsigned long ulEventTime, unsigned long ulFlushTime, unsigned long ulPreBufferTime, unsigned long ulMaxRecordTime );

DLL_API bool KStartRecord2( HANDLE h, unsigned short usID, unsigned short usType,
		char * szPath,
		unsigned long ulEventTime,
		unsigned long ulFlushTime,
		unsigned long ulMaxRecordTime,
		bool bEventRecord, bool bManualRecorder );

DLL_API void KStopRecord2( HANDLE h );
DLL_API void KSetRecordingStatusCallback( HANDLE h, RECORDING_STATUS_CALLBACK lpfn, DWORD userparam);


DLL_API void KEnableDITrigger( HANDLE h, bool bEnable );


// PIR Config
typedef struct structural_MEDIA_PIR_CONFIG
{
	BOOL bEnable; // where n could be 0: Disable and 1: Enable
	DWORD dwSensitive; // sen: the sensitivity from 0~100. 0: means disable PIR motion sensor
	DWORD dwTime; // timer: the motion timer (0~300 seconds)
}MEDIA_PIR_CONFIG;

DLL_API bool KSetPIRConfig( HANDLE h, MEDIA_PIR_CONFIG * pPIRConfigo );
DLL_API bool KGetPIRConfig( HANDLE h, MEDIA_PIR_CONFIG * pPIRConfig );

//----> For ipcmrSetRS232 x81 Setting
//RS232 Setting
#define NET_N81			0x00		// N,    8, 1
#define NET_O81			0x08		// Odd,  8, 1
#define NET_E81			0x18		// Even, 8, 1

//NEW
//N:00 O:10 E:01 + 0:00 1:01 2:02
//8:1000 7:0111
#define NET_8N1			0x81		// N,    8, 1
#define NET_8O1			0x89		// Odd,  8, 1
#define NET_8E1			0x85		// Even, 8, 1

#define NET_8N2			0x82		// 8 Data bits, No parity check, 2 Stop bit
#define NET_8O2			0x8A		// 8 Data bits, Odd parity check, 2 Stop bit
#define NET_8E2			0x86		// 8 Data bits, Even parity check, 2 Stop bit
#define NET_7N2			0x72		// 7 Data bits, No parity check, 2 Stop bit
#define NET_7O2			0x7A		// 7 Data bits, Odd parity check, 2 Stop bit
#define NET_7E2			0x76		// 7 Data bits, Even parity check, 2 Stop bit 


typedef void ( WINAPI *DOWNLOAD_PROGRESS_CALLBACK	)( DWORD UserParam, __int64 filesize, __int64 downloadsize, __int64 downloadtime );

DLL_API void KSetDownloadProgressCallback( HANDLE h, DWORD param, DOWNLOAD_PROGRESS_CALLBACK lpfn );
DLL_API void KSetDownloadLocalFileName( HANDLE h, char * fullfilename );
DLL_API void KEnableDeleteFileAfterClose( HANDLE h, BOOL flg );

typedef enum
{
	CDECFMT_NONE = 0,	// Default YV12
	CDECFMT_BGR24,		// BGR BGR ...
	CDECFMT_BGR32,		// BGRA BGRA ...
	CDECFMT_YUY2,		// Y0 U0 Y1 V0 ...
	NUM_OF_CDEC_FORMAT

} CDEC_FORMAT;

DLL_API void KSetFormat( HANDLE h, CDEC_FORMAT fmtType );
DLL_API void KSetDeblock( HANDLE h, BOOL bEnable );
DLL_API void KSetQuality( HANDLE h, DWORD destQuality );

DLL_API void KEnableFixJitter( HANDLE h, BOOL flg);



/************************************************************************/
/*		FishEye	Mode                                                    */
/************************************************************************/
enum EN_FISHEYE_MODULE
{
	enACTi_KCM3911			= 0,//Support KCM3911
	enACTi_KCM7911			= 1,//Support KCM7911
	enACTi_B54				= 2,//Support B54
	enACTi_B55				= 3,//Support B55
	enACTi_B56				= 4,//Support B56
	enACTi_E96				= 5,//Support E96
	enACTi_E919				= 6,//Support E919
	enACTi_E921             = 7,//Support E921
	enACTi_E923				= 8,//Support E923	
	enACTi_Auto				= 999,//Support all camera
};

enum EN_FISHEYE_MODE
{
	enWall_Dewarping			= 0,
	enWall_Panorama				= 1,
	enCeiling_Dewarping			= 2,
	enCeiling_Panorama			= 3,
	enCeiling_DoublePanorama	= 4,
	enGround_Dewarping			= 5,
	enGround_Panorama			= 6,
	enGround_DoublePanorama		= 7,

	enWall_DoublePanorama	= 20,
	enWall_PanoramaFocus = 21,
	enWall_Surround,
	enCeiling_PanoramaFocus = 23,
	enCeiling_Surround,
};

enum EN_FISHEYE_COORD_MODE
{
	//Select a Wall Panorama Coordinate, then we can get Wall PTZ Coordinate(pan and tilt)
	enWall_Panorama2PTZ			= 0,
	//Select a Ceiling Panorama Coordinate, then we can get Ceiling PTZ Coordinate(pan and tilt)
	enCeiling_Panorama2PTZ		= 1,
	//Select a Ground Panorama Coordinate, then we can get Ground PTZ Coordinate(pan and tilt)
	enGround_Panorama2PTZ		= 2,
	//Select a Fisheye Coordinate, then we can get Ceiling PTZ Coordinate(pan and tilt).
	enCeiling_Fisheye2PTZ		= 3,
	//Select a Fisheye Coordinate, then we can get Ground PTZ Coordinate(pan and tilt).
	enGround_Fisheye2PTZ		= 4,
	//Select a Fisheye Coordinate, then we can get Wall PTZ Coordinate(pan and tilt).
	enWall_Fisheye2PTZ			= 5,
	//Select a Wall De-warping Coordiante, then we can get Wall PTZ Coodinate(pan, and tilt).
	enWall_Dewarping2PTZ		= 6,
	//Select a Ceiling De-warping Coordiante, then we can get Ceiling PTZ Coodinate(pan, and tilt).
	enCeiling_Dewarping2PTZ		= 7,
	//Select a Ground De-warping Coordiante, then we can get Ground PTZ Coodinate(pan, and tilt).
	enGround_Dewarping2PTZ		= 8,
};



/************************************************************************/
/*		Wall Parameter                                                  */
/************************************************************************/
//Wall Dewarping Structure
struct ST_WALL_D
{
	int Pan;//相對座標移動量
	int Tilt;//相對座標移動量
	int Zoom;//Zoom in
};

//Wall Panorama Structure
struct ST_WALL_P
{
	double ViewX;//固定Widthxheight, 改變可視廣度(X軸)
	double ViewY;//固定Widthxheight, 改變可視廣度(Y軸)
	int Tilt;//Tilt Move
};


/************************************************************************/
/*		Ceiling Parameter                                               */
/************************************************************************/
//Ceiling Dewarping Structure
struct ST_CEILING_D
{
	int Pan;//視角左右旋轉
	int Tilt;//視角上下旋轉
	int Zoom;//Zoom in
};


//Double Panorama Structure
struct ST_CEILING_DP
{
	int Move_XP;//相對座標移動
	double View;//改變可視範圍
	int ExtendCenterView;//0~90, the more the extend view, the larger view range but also higher distortion
};

struct ST_CEILING_P
{
	double View;//改變可視範圍
	int Pan;//Pan Move
};

/************************************************************************/
/*		Ground Parameter                                                */
/************************************************************************/
//Ground Dewarping Structure
struct ST_GROUND_D
{
	int Pan;//Pan Move
	int Tilt;//Tilt Move
	int Zoom;//Zoom scale
};


//Double Panorama Structure
struct ST_GROUND_DP
{
	int Move_XP;//Move 
	double View;//View angle
	int ExtendCenterView;//0~90, the more the extend view, the larger view range but also higher distortion
};

struct ST_GROUND_P
{
	double View;//view angle
	int Pan;//Pan Move
};

struct ST_RECTANGLE
{
	int RectNumber;//the number of rectangle image
	int RectStartX;// start position x-coordinate
	int RectStartY;//start position y-coordinate
	int RectWidth;//rectangle width 
	int RectHeight;//rectangle height
};

/************************************************************************/
/*	FishEye Parameter                                                   */
/************************************************************************/

struct ST_FISHEYE_PARAMETER
{

	//Wall Parameter
	ST_WALL_D		Wall_D;//Wall De-Warping Parameter
	ST_WALL_P		Wall_P;//Wall Panorama Parameter

	//Ceiling Parameter
	ST_CEILING_D	Ceiling_D;//Ceiling De-Warping Parameter
	ST_CEILING_P	Ceiling_P;//Ceiling Panorama Parameter
	ST_CEILING_DP	Ceiling_DP;//Ceiling Double Panorama Parameter
	
	//Ground Parameter 
	ST_GROUND_D  Ground_D;//Ceiling De-Warping Parameter
	ST_GROUND_P  Ground_P;//Ceiling Panorama Parameter
	ST_GROUND_DP Ground_DP;//Ceiling Double Panorama Parameter
	
	ST_RECTANGLE	Rectangle;//the area of rectangle in the output image
};

//struct ST_FISHEYE_COORD
//{
//	int InputPanoramaCoordX;//Panorama Coordinate X
//	int InputPanoramaCoordY;//Panorama Coordinate Y
//	int InputFisheyeCoordX;//Original fisheye coordinate X
//	int InputFisheyeCoordY;//Original fisheye coordinate Y
//	int TransformTilt;//De-warping Coordinate "Tilt" from transformation of input Panorama/fisheye image
//	int TransformPan;//De-warping Coordinate "Pan" from transformation of input Panorama/fisheye image
//
//};

typedef struct _tagFishEyeCurrentCoordinate
{
	int Pan;
	int Tilt;
	int Zoom;

	int point_counts;
	POINT pts[128];

}stFishEyeCurrentCoordinate;

// FishEye
DLL_API void KEnableFishEye( HANDLE h, BOOL bEnable );
DLL_API void KEnableFisyEyeSubWindow( HANDLE h, BOOL bEnable );
DLL_API void KSetFishEyeMode( HANDLE h, EN_FISHEYE_MODE mode );
DLL_API BOOL KSetFishEyeModule( HANDLE h, EN_FISHEYE_MODULE module, BOOL auto_center );
DLL_API void KSetFishEyeRotationAngle( HANDLE h, int idx, double ViewX, double ViewY );
DLL_API void KGetFishEyeCurrentCoordinate( HANDLE h, stFishEyeCurrentCoordinate * orgcoord );
DLL_API void KFishEyeRelativeMove( HANDLE h, int idx, int x, int y, int z );
DLL_API void KFishEyeMoveTo( HANDLE h, int idx, int x, int y, int z );
DLL_API void KFishEyeWindowRelativeMove( HANDLE h, int idx, int x, int y );
DLL_API BOOL KFishEyeSetCircle( HANDLE h, int x, int y, int radius, int width, int height );
DLL_API BOOL KFishEyeGetCircle( HANDLE h, int & x, int & y, int & radius, int & width, int & height );
//DLL_API BOOL KFishEyeGetCircle( HANDLE h, int & x, int & y, int & radius );
DLL_API void KSetFishEyePTZMoveTo( HANDLE h, int idx, int x, int y, int z );
DLL_API void KGetFishEyePTZMoveTo( HANDLE h, int idx, int * x, int * y, int * z );
DLL_API void KGetFishEyeRotationAngle( HANDLE h, int idx, double * ViewX, double * ViewY );
DLL_API BOOL KFishEyeGetDefaultCircle( HANDLE h, int & x, int & y, int & radius, int & width, int & height );


typedef struct _tagSubWindowInfo
{
	int iX;
	int iY;
	int iWidth;
	int iHeight;
}stSubWindowInfo;


DLL_API void KEnableSubWindow( HANDLE h, BOOL flg );
DLL_API void KGetSubWindowInfo( HANDLE h, stSubWindowInfo * subwindowinfo );

// CODEC 

DLL_API HANDLE KCODECCreate();
DLL_API void KCODECReset( HANDLE h );
DLL_API BOOL KCODECDecode1( HANDLE h, BYTE * in_buf, int in_buf_len, BYTE ** out_buf, int * out_buf_len );
DLL_API BOOL KCODECDecode2( HANDLE h, BYTE * in_buf, int in_buf_len, BITMAPINFO ** bimapinfo, BYTE ** out_buf, int * out_buf_len );
DLL_API void KCODECRelease( HANDLE h );

#endif

