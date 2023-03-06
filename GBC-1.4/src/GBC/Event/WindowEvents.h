#pragma once

#include "GBC/Event/Event.h"

namespace gbc
{
	class WindowCloseEvent : public Event
	{
	public:
		_GBC_EVENT_GET_STATIC_TYPE(EventType::WindowClose);

		constexpr WindowCloseEvent()
			: Event{GetStaticType()} {}

#if GBC_ENABLE_LOGGING
		virtual std::string ToString() const override;
#endif
	};

	class WindowResizeEvent : public Event
	{
	public:
		_GBC_EVENT_GET_STATIC_TYPE(EventType::WindowResize);

		constexpr WindowResizeEvent(uint32_t width, uint32_t height)
			: Event{GetStaticType()}, m_Width{width}, m_Height{height} {}

		constexpr auto GetWidth() const noexcept -> uint32_t { return m_Width; }
		constexpr auto GetHeight() const noexcept -> uint32_t { return m_Height; }

#if GBC_ENABLE_LOGGING
		virtual std::string ToString() const override;
#endif
	private:
		uint32_t m_Width;
		uint32_t m_Height;
	};

	class WindowFramebufferResizeEvent : public Event
	{
	public:
		_GBC_EVENT_GET_STATIC_TYPE(EventType::WindowFramebufferResize);

		constexpr WindowFramebufferResizeEvent(uint32_t width, uint32_t height)
			: Event{GetStaticType()}, m_Width{width}, m_Height{height} {}

		constexpr auto GetFramebufferWidth() const noexcept -> uint32_t { return m_Width; }
		constexpr auto GetFramebufferHeight() const noexcept -> uint32_t { return m_Height; }

#if GBC_ENABLE_LOGGING
		virtual std::string ToString() const override;
#endif
	private:
		uint32_t m_Width;
		uint32_t m_Height;
	};

	class WindowMoveEvent : public Event
	{
	public:
		_GBC_EVENT_GET_STATIC_TYPE(EventType::WindowMove);

		constexpr WindowMoveEvent(uint32_t x, uint32_t y)
			: Event{GetStaticType()}, m_X{x}, m_Y{y} {}

		constexpr auto GetX() const noexcept -> uint32_t { return m_X; }
		constexpr auto GetY() const noexcept -> uint32_t { return m_Y; }

#if GBC_ENABLE_LOGGING
		virtual std::string ToString() const override;
#endif
	private:
		uint32_t m_X;
		uint32_t m_Y;
	};

	class WindowFocusEvent : public Event
	{
	public:
		_GBC_EVENT_GET_STATIC_TYPE(EventType::WindowFocus);

		constexpr WindowFocusEvent(bool focused)
			: Event{GetStaticType()}, m_Focused{focused} {}

		constexpr auto IsFocused() const noexcept -> bool { return m_Focused; }

#if GBC_ENABLE_LOGGING
		virtual std::string ToString() const override;
#endif
	private:
		bool m_Focused;
	};

	class WindowMinimizeEvent : public Event
	{
	public:
		_GBC_EVENT_GET_STATIC_TYPE(EventType::WindowMinimize);

		constexpr WindowMinimizeEvent(bool minimized)
			: Event{GetStaticType()}, m_Minimized{minimized} {}

		constexpr auto IsMinimized() const noexcept -> bool { return m_Minimized; }

#if GBC_ENABLE_LOGGING
		virtual std::string ToString() const override;
#endif
	private:
		bool m_Minimized;
	};

	class WindowMaximizeEvent : public Event
	{
	public:
		_GBC_EVENT_GET_STATIC_TYPE(EventType::WindowMaximize);

		constexpr WindowMaximizeEvent(bool maximized)
			: Event{GetStaticType()}, m_Maximized{maximized} {}

		constexpr auto IsMaximized() const noexcept -> bool { return m_Maximized; }

#if GBC_ENABLE_LOGGING
		virtual std::string ToString() const override;
#endif
	private:
		bool m_Maximized;
	};

	class WindowPathDropEvent : public Event
	{
	public:
		_GBC_EVENT_GET_STATIC_TYPE(EventType::WindowPathDrop);

		constexpr WindowPathDropEvent(uint32_t pathCount, const char** paths)
			: Event{GetStaticType()}, m_PathCount{pathCount}, m_Paths{paths} {}

		constexpr auto GetPathCount() const noexcept -> uint32_t { return m_PathCount; }
		constexpr auto GetPaths() const noexcept -> const char* const* const { return m_Paths; }

#if GBC_ENABLE_LOGGING
		virtual std::string ToString() const override;
#endif
	private:
		uint32_t m_PathCount;
		const char** m_Paths;
	};
	

	class WindowContentScaleEvent : public Event
	{
	public:
		_GBC_EVENT_GET_STATIC_TYPE(EventType::WindowContentScale);

		constexpr WindowContentScaleEvent(float scaleX, float scaleY)
			: Event{GetStaticType()}, m_ScaleX{scaleX}, m_ScaleY{scaleY} {}

		constexpr auto GetScaleX() const noexcept -> float { return m_ScaleX; }
		constexpr auto GetScaleY() const noexcept -> float { return m_ScaleY; }

#if GBC_ENABLE_LOGGING
		virtual std::string ToString() const override;
#endif
	private:
		float m_ScaleX;
		float m_ScaleY;
	};

	class WindowRefreshEvent : public Event
	{
	public:
		_GBC_EVENT_GET_STATIC_TYPE(EventType::WindowRefresh);

		constexpr WindowRefreshEvent()
			: Event{GetStaticType()} {}

#if GBC_ENABLE_LOGGING
		virtual std::string ToString() const override;
#endif
	};
}