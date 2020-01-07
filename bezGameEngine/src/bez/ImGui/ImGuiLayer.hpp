#ifndef IMGUILAYER_HPP
#define IMGUILAYER_HPP

#include <bez/Layer.hpp>

namespace bez {

class ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		void onAttach() override;
		void onDetach() override;
		void onUpdate() override;
		void onEvent(Event &) override;

	protected:
	private:
		double m_time;
};

} // namespace bez

#endif // IMGUILAYER_HPP

