
#include "Server.h"

/*  < Echo 서버 시나리오 >
* 0. 서버 시작
* 1. 접속대기 소켓 생성
* 2. 포트 바인딩
* 3. 접속대기 상태로 전환
* 4. 클라이언트 접속 처리 및 대응
* 4-1. 클라이언트 연결을 받아들이고 새로운 소켓 생성(개방)
* 4-2. 클라이언트로부터 수신
* 4-3. 수신한 거 그대로 다시 전송
* 4-4. 클라이언트의 연결 종료
* 5. 리슨 소켓 닫기
* 6. 서버 정상 종료
*/

const unsigned short PORT_NUMBER = 3100;

int main()
{
    boost::asio::io_context io_context;

    // server s(io_context, std::atoi(argv[1])); 
    server s(io_context, PORT_NUMBER);

    try
    {
        cout << "Server Start..." << endl;
        io_context.run();
        cout << "Server closed..." << endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}