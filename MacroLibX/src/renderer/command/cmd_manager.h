/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:48:52 by maldavid          #+#    #+#             */
/*   Updated: 2023/12/08 19:07:00 by kbz_8            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MLX_COMMAND_MANAGER__
#define __MLX_COMMAND_MANAGER__

#include <array>

#include <volk.h>
#include <core/profile.h>
#include <renderer/core/render_core.h>
#include <renderer/command/vk_cmd_pool.h>
#include <renderer/command/vk_cmd_buffer.h>

namespace mlx
{
	class CmdManager
	{
		public:
			CmdManager() = default;

			void init() noexcept;
			void beginRecord(int active_image_index);
			void endRecord(int active_image_index);
			void destroy() noexcept;

			inline CmdPool& getCmdPool() noexcept { return _cmd_pool; }
			inline CmdBuffer& getCmdBuffer(int i) noexcept { return _cmd_buffers[i]; }

			~CmdManager() = default;

		private:
			std::array<CmdBuffer, MAX_FRAMES_IN_FLIGHT> _cmd_buffers;
			CmdPool _cmd_pool;
	};
}

#endif
