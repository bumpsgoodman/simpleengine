Simple Engine Rule

Scene
Scene을 만들 시 IScene 상속
Init(), Clear() 함수 정의
Scene 추가 시 Game::Init() 함수에서 SceneManager::GetInstance()->LoadScene<Sokoban>("Sokoban");
	과 같이 SceneManager로 추가
GameObject
GameObject는 기본적으로 new를 사용해서 할당
Component 추가 시 AddComponent() 함수 호출
Component
Component를 만들 시 IComponent 상속
Init(), Update(), Clear() 함수 정의
중간에 프로그램을 종료해야 한다면 Application::Quit() 함수 사용
