<div align="center">
  <h1>🧟‍♂️ Survival (2D Zombie) - 탑다운 좀비 서바이벌 슈팅 게임</h1>
  <p><strong>C++ 및 OpenGL 기반 자체 2D 엔진으로 구현한 탑다운 웨이브 서바이벌 액션 슈팅 게임</strong></p>

  <!-- 방패 뱃지들 -->
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++">
  <img src="https://img.shields.io/badge/OpenGL-5586A4?style=for-the-badge&logo=opengl&logoColor=white" alt="OpenGL">
  <img src="https://img.shields.io/badge/FMOD_Ex-000000?style=for-the-badge" alt="FMOD Ex">
  <img src="https://img.shields.io/badge/Custom_2D_Engine-8A2BE2?style=for-the-badge" alt="Custom 2D Engine">
  <img src="https://img.shields.io/badge/No_AI_Used-10B981?style=for-the-badge" alt="AI 미사용">
  <br><br>
</div>

## 📌 Project Overview
- **개발 기간:** 2019 (학부 프로젝트)
- **개발 인원:** 2인 팀 프로젝트 (프로그래밍 전담 1명, 기획/리소스 1명)
- **담당 역할:** 메인 프로그래머 (자체 2D 프레임워크 설계, 렌더링 파이프라인, 게임 로직, FMOD 사운드 연동 전담)
- **사용 기술:** C++, OpenGL, FMOD Ex Audio Engine, 자체 2D 게임 프레임워크
- **장르:** 2D 탑다운 서바이벌 액션 슈팅

---

## 🎮 Game Concept
좀비 바이러스가 창궐한 묘지 한가운데에서 살아남아 헬기를 타고 탈출하는 탑다운 서바이벌 슈팅 게임입니다. 
시야가 극도로 제한된 어두운 밤, 사방에서 몰려드는 좀비 웨이브를 다양한 생존자 고유 스킬과 총기 사격, 지뢰를 활용해 물리치며 생존 일수를 버텨내는 긴박한 게임플레이를 제공합니다.

### 💡 주요 특징 (Key Highlights)
1. **6개 씬 아키텍처 및 팝업 시스템:** 
   `D_SCENE` 씬 관리자를 기반으로 `Load → Logo → Menu → Method → Game → Result` 6개 씬 라이프사이클을 체계적으로 분리하고, 카메라 좌표 추종 인게임 일시정지·옵션 팝업(`CPopupWinRoot`)을 구축했습니다.
2. **`CUnit` 상속 기반 3종 생존자 캐릭터 및 차별화된 스킬셋:**
   `CHero` 기본 틀을 상속받아 회사원(`CMan`, 공격력 2배 및 임시 체력 버프), 의사(`CDoctor`, 자가 치유 및 10초 초과 복귀), 군인(`CSoldier`, 마우스 지정 수류탄 폭격 `CGrenade`)의 고유 전용기(`Q`)를 구현했습니다.
3. **정밀 마우스 조준 사격과 4방향 스프라이트 회전:**
   `ScreenToWorld` 좌표 역변환 및 방향 벡터 내적/외적 연산을 통해 마우스 커서 방향으로 상하좌우 4방향 시선 스프라이트 전환, 총구 회전, 피격 혈흔 입사각을 정밀 계산합니다.
4. **암전 시야 연출 및 동적 라이팅 마스크:**
   묘지 맵 위에 방사형 조명 마스크(`Light_1.png`)를 OpenGL 블렌딩(`GL_DST_COLOR`, `GL_ONE_MINUS_DST_ALPHA`)으로 합성하여 플레이어 주변 시야만 밝히고, 생존 일자가 지날수록 시야 반경(`LightSize`)을 `5.0f → 1.0f`로 점진 축소해 심리적 공포감을 극대화했습니다.
5. **체계적인 몬스터 웨이브 & 5일차 대형 보스전:**
   40슬롯 몬스터 풀(`CNormal_1~3`)과 45슬롯 그림자 오브젝트 풀, 원거리 산성액을 뱉는 `Spitter`(`CSpecial`), 5일차에 등장하는 대형 보스 좀비(`BigSizeMonster`) 및 탈출 헬기 오프닝/엔딩 컷신을 완성도 높게 구현했습니다.

---

## 🛠 Tech Stack & Architecture

### **Core Stack**
- **Language:** C++
- **Graphics API:** OpenGL (Fixed / Programmable Pipeline)
- **Audio:** FMOD Ex 래퍼 (`D_SOUND`, BGM/SFX/심장박동/몬스터 사운드 채널 분기)
- **Framework:** 자체 제작 C++ 2D 프레임워크 (Plane, Mesh, Animation, Camera, Scene, Ray-AABB 충돌)

### **Game Loop & System Flow**
1. **로비 & 모드/생존자 선택 (`Load · Logo · Menu · Method`):** 스토리 모드/챌린지 모드 및 3종 캐릭터 선택, 조작 안내
2. **헬기 추락 오프닝 연출 (`CIntro`):** 무전 효과음 및 헬기 추락 폭발 연출 후 인게임 진입 (클릭 시 스킵 가능)
3. **전투 루프 (`CGun · CBullet · CBlood · CEffect`):** 10발 탄환 풀 사격, `R` 탄창 낙하 재장전, 4종 피격 반응 연출
4. **스킬 & 웨이브 방어 (`CUnit · CHero · CMine · CMonster`):** `Q` 고유 스킬 및 `E` 단일 지뢰, 일차별 시야 축소 및 보스전
5. **결과 정산 (`CResultScene`):** 생존 일수, 좀비 처치 수, 최종 점수 통계 출력 및 탈출/사망 분기

---

## 🔥 Challenge & Solution (Troubleshooting)

### 1. 초기 사격 타격감 부재 및 피격 피드백 부족 해결
**Problem:** 
초기 프로토타입 사격 구현 시 탄환 충돌(`Bullet_VS_MonsterColision`) 판정 후 몬스터 체력 수치만 단순 차감되어, 플레이어가 좀비를 정확히 명중시켰는지 직관적으로 인지하기 어렵고 슈팅 액션 특유의 타격감이 현저히 떨어졌습니다.

**Solution:** 
시각, 물리, 청각, 잔류 효과의 4중 피격 피드백 시스템을 결합했습니다:
1. **적색 점멸:** 피격 플래그(`m_bHit`) 활성화 시 0.3초 동안 스프라이트 컬러를 `SetColor(255, 0, 0)`으로 변환.
2. **물리 넉백:** 플레이어 위치 반대 방향 정규화 벡터(`* 3.0f`)를 추출하여 `Lerp` 보간으로 몬스터를 뒤로 밀어냄.
3. **입체 사운드:** 발포음(`Gun.mp3`)과 함께 4개 슬롯으로 중복 충돌을 방지하는 몬스터 피격음(`Hit_Zombie.mp3` 등) 재생.
4. **다이내믹 혈흔:** 탄환 진행 방향 벡터를 기반으로 회전된 피격 혈흔(`CBlood`)과 바닥 잔류 혈흔(`CEffect`)을 실시간 인스턴스화.
이로써 직관적인 피격 인지와 시원한 타격감을 확보했습니다.

---

### 2. 67프레임 안개 시퀀스 반투명 블렌딩 및 왕복 애니메이션 루프 구현
**Problem:** 
로비(MenuScene)와 결과 화면(ResultScene)의 배경 아트 위에 으스스한 분위기를 내기 위해 검은 배경이 포함된 67프레임 안개 이미지 시퀀스(`Fog_1/output-0~66.png`)를 얹으려 했습니다. 하지만 기본 텍스처 출력 방식으로는 검은 배경이 뒤쪽 배경 이미지를 완전히 덮어버리고, 기존 `CEMAnimation` 클래스로는 자연스러운 연속 왕복 연출이 지원되지 않았습니다.

**Solution:** 
OpenGL 그래픽스 파이프라인의 블렌딩 함수를 커스텀 적용했습니다:
1. `SetBlendFunc(GL_DST_COLOR, GL_ONE)` 및 `SetAlpha(0.5f)`를 조합하여 안개 텍스처의 검은 배경 영역은 투명하게 날리고 밝은 안개 입자만 50% 반투명하게 뒷배경과 곱셈/가산 합성되도록 구성했습니다.
2. `CEMPlane* m_pFog[67]` 배열에 프레임을 적재한 뒤, `CFog::Update`에서 `0.15s` 타이머 주기로 인덱스를 `0 → 66 → 0`으로 왕복 순회하며 활성 프레임만 `SetShow(true)`하는 경량 루프를 구현해 성능 저하 없이 영화 같은 안개 배경 연출을 완성했습니다.
