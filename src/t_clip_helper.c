/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_clip_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:31:32 by obelange          #+#    #+#             */
/*   Updated: 2017/03/17 11:31:33 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	t_clip_print(t_clip *clip)
{
	ft_printf("t_clip->ssignal: %s\n", clip->ssignal);
	ft_printf("t_clip->lsignal: %s\n", clip->lsignal);
	ft_printf("t_clip->lflag: %s\n", clip->lflags);
	ft_printf("t_clip->sflag: %s\n", clip->sflags);
	ft_printf("t_clip->valid lflags:\n");
	ft_strlist_print(clip->valid_lflags);
	ft_printf("t_clip->args list:\n");
	ft_strlist_print(clip->args);
}

int		ls_arg_validator(char* str)
{
	if (str)
	{
		return (1);
	}
	return (0);
}

void	ls_cli_error(int x, char *err)
{
	if (x < 1)
	{
		write(2, err, ft_strlen(err));
		exit(1);
	}
}

void	t_clip_nope(t_context *context)
{

	// context->invalid = ft_strlist_add(context->invalid, "Applications");
	// context->invalid = ft_strlist_add(context->invalid, "Library");
	// context->invalid = ft_strlist_add(context->invalid, "Network"); 
	// context->invalid = ft_strlist_add(context->invalid, "System");
	// context->invalid = ft_strlist_add(context->invalid, "Users");
	// context->invalid = ft_strlist_add(context->invalid, "Volumes");
	// context->invalid = ft_strlist_add(context->invalid, "bin");
	// context->invalid = ft_strlist_add(context->invalid, "cores");
	// context->invalid = ft_strlist_add(context->invalid, "dev");
	// context->invalid = ft_strlist_add(context->invalid, "etc"); 
	// context->invalid = ft_strlist_add(context->invalid, "goinfre");
	// context->invalid = ft_strlist_add(context->invalid, "home");
	// context->invalid = ft_strlist_add(context->invalid, "installer.failurerequests");
	// context->invalid = ft_strlist_add(context->invalid, "net"); 
	
	// context->invalid = ft_strlist_add(context->invalid, "munki_repo");






	context->invalid = ft_strlist_add(context->invalid, ".");
	context->invalid = ft_strlist_add(context->invalid, "..");
	// context->invalid = ft_strlist_add(context->invalid, "Applications");
	// context->invalid = ft_strlist_add(context->invalid, "Library"); 
	context->invalid = ft_strlist_add(context->invalid, "library.obelange");
	// context->invalid = ft_strlist_add(context->invalid, "obelange");
	// context->invalid = ft_strlist_add(context->invalid, "intrav2cdn");
	// context->invalid = ft_strlist_add(context->invalid, "reposado");
	// context->invalid = ft_strlist_add(context->invalid, "softs");
	context->invalid = ft_strlist_add(context->invalid, "systemstats");
	context->invalid = ft_strlist_add(context->invalid, "admin"); 
	context->invalid = ft_strlist_add(context->invalid, "internship");
	// context->invalid = ft_strlist_add(context->invalid, "offer");

	context->invalid = ft_strlist_add(context->invalid, "1466869587-5072-8646");
	context->invalid = ft_strlist_add(context->invalid, "1486113442-21997-3925");
	context->invalid = ft_strlist_add(context->invalid, "464");
	context->invalid = ft_strlist_add(context->invalid, "Resources"); 
	context->invalid = ft_strlist_add(context->invalid, "Archives");
	context->invalid = ft_strlist_add(context->invalid, "munki");
	context->invalid = ft_strlist_add(context->invalid, "Automator");
	context->invalid = ft_strlist_add(context->invalid, "Extensions");
	context->invalid = ft_strlist_add(context->invalid, "LaunchAgents");
	context->invalid = ft_strlist_add(context->invalid, "LaunchDaemons");
	context->invalid = ft_strlist_add(context->invalid, "Exception"); 
	context->invalid = ft_strlist_add(context->invalid, "PrivateFrameworks");
	context->invalid = ft_strlist_add(context->invalid, "Devices");	

	context->invalid = ft_strlist_add(context->invalid, "Keychains");
	context->invalid = ft_strlist_add(context->invalid, "archive");
	context->invalid = ft_strlist_add(context->invalid, "8eu9ua5mjpzpzt2vwk9q31pvwa5xdn6bnw");	
	context->invalid = ft_strlist_add(context->invalid, "yzchtyc0otwpfvfyf4xu5qup5khtgsu7st");
	context->invalid = ft_strlist_add(context->invalid, "o1b83gtjckvj2yvhdx1v3sz0nrpta28tjv");	
	context->invalid = ft_strlist_add(context->invalid, "jjcm4jo4zjyp88khardh9avsu1ixbf6kxb");
	context->invalid = ft_strlist_add(context->invalid, "ubizb5ahj5q0ds5yol3x2rp621xl86kng6");
	context->invalid = ft_strlist_add(context->invalid, "otd5kuhpv2i3nuqe10g2x2ajl17pp7jdr9");
	context->invalid = ft_strlist_add(context->invalid, "2cioz8b3eckp22wu2208qazqalzzbu94y8"); 
	context->invalid = ft_strlist_add(context->invalid, "hfj5t2jgo6wn0evu37f2xak7npbuhj6k90");
	context->invalid = ft_strlist_add(context->invalid, "zje0qtn73w686lans8avj3t8f8txruq0mc");
	context->invalid = ft_strlist_add(context->invalid, "5bnklwoqfl3liz5v1ut7zg3vkpkpe2zikg");
	context->invalid = ft_strlist_add(context->invalid, "ay4q41mkptevrm0p60cd4fdnp00gb1hd6f");
	context->invalid = ft_strlist_add(context->invalid, "rxytsei823m5z0qwi1voykiontix1y80kd");
	context->invalid = ft_strlist_add(context->invalid, "8z1p9mydwici45ionothpje4u883p3uo5k"); 
	context->invalid = ft_strlist_add(context->invalid, "gut5yry16heg0bamgewsrjuw6kixklj5kf");
	context->invalid = ft_strlist_add(context->invalid, "bd11dp9ia2g9i5dvvbwqisqw09ipfa3asy");
	context->invalid = ft_strlist_add(context->invalid, "LoL"); 
	context->invalid = ft_strlist_add(context->invalid, "5362");
	context->invalid = ft_strlist_add(context->invalid, "Desktop");
	context->invalid = ft_strlist_add(context->invalid, "Downloads");
	context->invalid = ft_strlist_add(context->invalid, "ByHost");
	context->invalid = ft_strlist_add(context->invalid, "DiagnosticReports");
	context->invalid = ft_strlist_add(context->invalid, "VOTKeyboardMaps");
	context->invalid = ft_strlist_add(context->invalid, "DeepBreathing.app");
	context->invalid = ft_strlist_add(context->invalid, "AccessibilityBundles");
	context->invalid = ft_strlist_add(context->invalid, "nano");	
	context->invalid = ft_strlist_add(context->invalid, "ActivityDataProvider.bundle");
	context->invalid = ft_strlist_add(context->invalid, "ServiceDefinitions");	
	context->invalid = ft_strlist_add(context->invalid, "Intents.framework");
	context->invalid = ft_strlist_add(context->invalid, "Bridge.app");
	context->invalid = ft_strlist_add(context->invalid, "CoreAddition");
	context->invalid = ft_strlist_add(context->invalid, "asl"); 
	context->invalid = ft_strlist_add(context->invalid, "Truffles");
	context->invalid = ft_strlist_add(context->invalid, "ofitch");
	// context->invalid = ft_strlist_add(context->invalid, "rxytsei823m5z0qwi1voykiontix1y80kd");
	// context->invalid = ft_strlist_add(context->invalid, "8z1p9mydwici45ionothpje4u883p3uo5k"); 
	// context->invalid = ft_strlist_add(context->invalid, "gut5yry16heg0bamgewsrjuw6kixklj5kf");
	// context->invalid = ft_strlist_add(context->invalid, "bd11dp9ia2g9i5dvvbwqisqw09ipfa3asy");
	// context->invalid = ft_strlist_add(context->invalid, "LoL"); 
	// context->invalid = ft_strlist_add(context->invalid, "5362");
	// context->invalid = ft_strlist_add(context->invalid, "Desktop");
	// context->invalid = ft_strlist_add(context->invalid, "Downloads");
	// context->invalid = ft_strlist_add(context->invalid, "ByHost");
	// context->invalid = ft_strlist_add(context->invalid, "DiagnosticReports");
	// context->invalid = ft_strlist_add(context->invalid, "Local Storage");





}





