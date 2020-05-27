# Simple Engine Rule

## 공통

기본적으로 모든 객체는 new를 사용하여 객체화
모든 Scene은 IScene을 상속받아 작성
모든 Component는 IComponent를 상속받아 작성

## Scene

### Scene 작성
```bash
class SomeScene final : public IScene
```
Init(), Clear() 함수만 오버로딩 후 작성
```bash
void SomeScene::Init() { }
void SomeScene::Clear() { }
```

### Scene 등록

Game::Init() 함수에서 SceneManager를 통해 Scene 등록

```bash
void Game::Init()
{
    .
    .
    .
    .
    SceneManager::GetInstance()->LoadScene<Sokoban>("Sokoban");
}
```

## GameObject

Component 추가 시 AddComponent() 함수 사용

```bash
GameObject obj = new GameObject();
obj->AddComponent(someComponent);
```

## Component

### Component 작성
```bash
class SomeComponent final : public IComponent
```

### Collider 작성

기본적으로 Collider를 상속받아 작성

```bash
class SomeCollider final : public Collider
```

OnTriggerEnter(), OnTriggerExit(), OnTriggerStay() 함수만 오버로딩 후 작성
```bash
void SomeCollider::OnTriggerEnter() { }
void SomeCollider::OnTriggerExit() { }
void SomeCollider::OnTriggerStay() { }
```

## 프로그램 종료

아래 함수를 사용하여 프로그램 종료

```bash
Apllication::Exit()
```
