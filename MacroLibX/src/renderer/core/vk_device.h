/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vk_device.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:13:42 by maldavid          #+#    #+#             */
/*   Updated: 2023/12/08 19:07:49 by kbz_8            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MLX_VK_DEVICE__
#define __MLX_VK_DEVICE__

#include <volk.h>
#include "vk_queues.h"
#include <core/profile.h>

namespace mlx
{
	class Device
	{
		public:
			void init();
			void destroy() noexcept;

			inline VkDevice& operator()() noexcept { return _device; }
			inline VkDevice& get() noexcept { return _device; }

			inline VkPhysicalDevice& getPhysicalDevice() noexcept { return _physicalDevice; }

		private:
			void pickPhysicalDevice();
			bool checkDeviceExtensionSupport(VkPhysicalDevice device);
			int deviceScore(VkPhysicalDevice device, VkSurfaceKHR surface);

		private:
			VkPhysicalDevice _physicalDevice = VK_NULL_HANDLE;
			VkDevice _device = VK_NULL_HANDLE;
	};
}

#endif // __MLX_VK_DEVICE__
