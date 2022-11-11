/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:04:48 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/11 16:57:12 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int	main(void)
{
	int	f41_no_nl, f42_with_nl, falternate_line_nl_no_nl, fbig_line_with_nl, fmultiple_line_with_nl;
	int	f41_with_nl, f43_no_nl, falternate_line_nl_with_nl, fempty, fmultiple_nlx5;
	int	f42_no_nl, f43_with_nl, fbig_line_no_nl, fmultiple_line_no_nl, fnl;
	
	char *r41_no_nl, *r42_with_nl, *ralternate_line_nl_no_nl, *rbig_line_with_nl, *rmultiple_line_with_nl;
	char	*r41_with_nl, *r43_no_nl, *ralternate_line_nl_with_nl, *rempty, *rmultiple_nlx5;
	char	*r42_no_nl, *r43_with_nl, *rbig_line_no_nl, *rmultiple_line_no_nl, *rnl;
	char	*rstdin;

	f41_no_nl = open("files/41_no_nl", O_RDONLY);
	f42_with_nl = open("files/42_with_nl", O_RDONLY);
	falternate_line_nl_no_nl = open("files/alternate_line_nl_no_nl", O_RDONLY);
	fbig_line_with_nl = open("files/big_line_with_nl", O_RDONLY);
	fmultiple_line_with_nl = open("files/multiple_line_with_nl", O_RDONLY);

	f41_with_nl = open("files/41_with_nl", O_RDONLY);
	f43_no_nl = open("files/43_no_nl", O_RDONLY);
	falternate_line_nl_with_nl = open("files/alternate_line_nl_with_nl", O_RDONLY);
	fempty = open("files/empty", O_RDONLY);
	fmultiple_nlx5 = open("files/multiple_nlx5", O_RDONLY);

	f42_no_nl = open("files/42_no_nl", O_RDONLY);
	f43_with_nl = open("files/43_with_nl", O_RDONLY);
	fbig_line_no_nl = open("files/big_line_no_nl", O_RDONLY);
	fmultiple_line_no_nl = open("files/multiple_line_no_nl", O_RDONLY);
	fnl = open("files/nl", O_RDONLY);

	r41_no_nl = (char *) 1;
	while (r41_no_nl || r42_with_nl || ralternate_line_nl_no_nl || rbig_line_with_nl || rmultiple_line_with_nl
	|| r41_with_nl || r43_no_nl || ralternate_line_nl_with_nl || rempty || rmultiple_nlx5
	|| r42_no_nl || r43_with_nl || rbig_line_no_nl || rmultiple_line_no_nl || rnl)
	{
		r41_no_nl = get_next_line(f41_no_nl);
		printf("r41_no_nl : [%s]\n\n", r41_no_nl);
		if (r41_no_nl)
			free(r41_no_nl);
		r42_with_nl = get_next_line(f42_with_nl);
		printf("r42_with_nl : [%s]\n\n", r42_with_nl);
		if (r42_with_nl)
			free(r42_with_nl);
		ralternate_line_nl_no_nl = get_next_line(falternate_line_nl_no_nl);
		printf("ralternate_line_nl_no_nl : [%s]\n\n", ralternate_line_nl_no_nl);
		if (ralternate_line_nl_no_nl)
			free(ralternate_line_nl_no_nl);
		rbig_line_with_nl = get_next_line(fbig_line_with_nl);
		printf("rbig_line_with_nl : [%s]\n\n", rbig_line_with_nl);
		if (rbig_line_with_nl)
			free(rbig_line_with_nl);
		rmultiple_line_with_nl = get_next_line(fmultiple_line_with_nl);
		printf("rmultiple_line_with_nl : [%s]\n\n", rmultiple_line_with_nl);
		if (rmultiple_line_with_nl)
			free(rmultiple_line_with_nl);

		r41_with_nl = get_next_line(f41_with_nl);
		printf("r41_with_nl : [%s]\n\n", r41_with_nl);
		if (r41_with_nl)
			free(r41_with_nl);
		r43_no_nl = get_next_line(f43_no_nl);
		printf("r43_no_nl : [%s]\n\n", r43_no_nl);
		if (r43_no_nl)
			free(r43_no_nl);
		ralternate_line_nl_with_nl = get_next_line(falternate_line_nl_with_nl);
		printf("ralternate_line_nl_with_nl : [%s]\n\n", ralternate_line_nl_with_nl);
		if (ralternate_line_nl_with_nl)
			free(ralternate_line_nl_with_nl);
		rempty = get_next_line(fempty);
		printf("rempty : [%s]\n\n", rempty);
		if (rempty)
			free(rempty);
		rmultiple_nlx5 = get_next_line(fmultiple_nlx5);
		printf("rmultiple_nlx5 : [%s]\n\n", rmultiple_nlx5);
		if (rmultiple_nlx5)
			free(rmultiple_nlx5);

		r42_no_nl = get_next_line(f42_no_nl);
		printf("r42_no_nl : [%s]\n\n", r42_no_nl);
		if (r42_no_nl)
			free(r42_no_nl);
		r43_with_nl = get_next_line(f43_with_nl);
		printf("r43_with_nl : [%s]\n\n", r43_with_nl);
		if (r43_with_nl)
			free(r43_with_nl);
		rbig_line_no_nl = get_next_line(fbig_line_no_nl);
		printf("rbig_line_no_nl : [%s]\n\n", rbig_line_no_nl);
		if (rbig_line_no_nl)
			free(rbig_line_no_nl);
		rmultiple_line_no_nl = get_next_line(fmultiple_line_no_nl);
		printf("rmultiple_line_no_nl : [%s]\n\n", rmultiple_line_no_nl);
		if (rmultiple_line_no_nl)
			free(rmultiple_line_no_nl);
		rnl = get_next_line(fnl);
		printf("rnl : [%s]\n\n", rnl);
		if (rnl)
			free(rnl);

		get_next_line(-1);
		get_next_line(open("notfound", O_RDONLY));
		printf("\n\n\n");
	}
	printf("Ecris quelque chose...\n");
	rstdin = get_next_line(0);
	printf("stdin : [%s]\n", rstdin);
	if (rstdin)
		free(rstdin);
}

