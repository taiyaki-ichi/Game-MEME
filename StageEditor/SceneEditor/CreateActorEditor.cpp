#include"CreateActorEditor.hpp"
#include"ActorEditor/GroundEditor.hpp"
#include"ActorEditor/PlayerEditor.hpp"



namespace StageEditor
{

	ActorEditorBase* CreateActorEditor(SceneEditor* sceneEditor, const std::string& actorName, std::vector<float>&& data)
	{
		ActorEditorBase* ptr = nullptr;
		
		////////////////////////////////////////////////////////////////////
		//������EditngActorBase�̔h���N���X��ǉ����Ă����A�A�߂�ǂ�����
		////////////////////////////////////////////////////////////////////

		if (actorName == "Ground")
			ptr = new GroundEditor(sceneEditor);
		if (actorName == "Player")
			ptr = new PlayerEditor(sceneEditor);



		///////////////////////////////////////////////////////////////////

		if (ptr && data.size() > 0)
			ptr->SetData(std::move(data));

		return ptr;
	}

}