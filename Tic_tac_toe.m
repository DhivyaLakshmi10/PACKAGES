classdef TTT < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure       matlab.ui.Figure
        Button_1       matlab.ui.control.Button
        WelcometoTicTacToefromMATLABHelperLabel  matlab.ui.control.Label
        Button_2       matlab.ui.control.Button
        Button_3       matlab.ui.control.Button
        Button_4       matlab.ui.control.Button
        Button_5       matlab.ui.control.Button
        Button_6       matlab.ui.control.Button
        Button_7       matlab.ui.control.Button
        Button_8       matlab.ui.control.Button
        Button_9       matlab.ui.control.Button
        NewGameButton  matlab.ui.control.Button
    end

    
    properties (Access = public)
        Player % 1 for Player1, 2 for Player 2
        mat % for matrix
    end
    
    methods (Access = public)
        
        function won = tictactoe(app,m)
            if (m(1,1) == m(1,2) && m(1,1) == m(1,3) && m(1,1) ~= -1)
                won = m(1,1);
            elseif (m(2,1) == m(2,2) && m(2,1) == m(2,3) && m(2,1) ~= -1)
                won = m(2,1);
            elseif (m(3,1) == m(3,2) && m(3,1) == m(3,3) && m(3,1) ~= -1)
                won = m(3,1);
                % Vertical
            elseif (m(1,1) == m(2,1) && m(1,1) == m(3,1) && m(3,1) ~= -1)
                won = m(1,1);
            elseif (m(1,2) == m(2,2) && m(1,2) == m(3,2) && m(1,2) ~= -1)
                won = m(1,2);
            elseif (m(1,3) == m(2,3) && m(1,3) == m(3,3) && m(1,3) ~= -1)
                won = m(1,3);
                % Diagonal
            elseif (m(1,1) == m(2,2) && m(1,1) == m(3,3) && m(1,1) ~= -1)
                won = m(1,1);
            elseif (m(1,3) == m(2,2) && m(1,3) == m(3,1) && m(2,2) ~= -1)
                won = m(1,3);
                % If no more slots are open, it's a tie
            elseif ~ismember(m, -1)
                won = 0;
            else
                won = -1;
            end
            if won == 1
                app.WelcometoTicTacToefromMATLABHelperLabel.Text ='Player 1 wins the game';
                startupFcn(app)
            elseif won == 2
                app.WelcometoTicTacToefromMATLABHelperLabel.Text ='Player 2 wins the game';
                startupFcn(app)
            elseif won == 0
                app.WelcometoTicTacToefromMATLABHelperLabel.Text ='The game is tied. Start new game';
            end
            
        end
        
    end
    

    methods (Access = private)

        % Code that executes after component creation
        function startupFcn(app)
            app.Button_1.Enable = 'off';
            app.Button_2.Enable = 'off';
            app.Button_3.Enable = 'off';
            app.Button_4.Enable = 'off';
            app.Button_5.Enable = 'off';
            app.Button_6.Enable = 'off';
            app.Button_7.Enable = 'off';
            app.Button_8.Enable = 'off';
            app.Button_9.Enable = 'off';
        end

        % Button pushed function: NewGameButton
        function NewGameButtonPushed(app, event)
            app.Button_1.Enable = 'on';
            app.Button_2.Enable = 'on';
            app.Button_3.Enable = 'on';
            app.Button_4.Enable = 'on';
            app.Button_5.Enable = 'on';
            app.Button_6.Enable = 'on';
            app.Button_7.Enable = 'on';
            app.Button_8.Enable = 'on';
            app.Button_9.Enable = 'on';
            app.Button_1.Text = '-';
            app.Button_2.Text = '-';
            app.Button_3.Text = '-';
            app.Button_4.Text = '-';
            app.Button_5.Text = '-';
            app.Button_6.Text = '-';
            app.Button_7.Text = '-';
            app.Button_8.Text = '-';
            app.Button_9.Text = '-';
            app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Player 1 Turn';
            app.Player = 1;
            app.mat = -1* ones(3,3);
        end

        % Button pushed function: Button_1
        function Button_1Pushed(app, event)
            if app.Player == 1
                app.Player = 2;
                app.Button_1.Text = 'O';
                app.mat(1,1) = 1;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Turn of Player 2';
            else
                app.Player = 1;
                app.Button_1.Text = 'X';
                app.mat(1,1) = 2;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Player 1 Turn';
            end
            app.Button_1.Enable = 'off';
            tictactoe(app,app.mat);
        end

        % Button pushed function: Button_2
        function Button_2Pushed(app, event)
            if app.Player == 1
                app.Player = 2;
                app.Button_2.Text = 'O';
                app.mat(1,2) = 1;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Turn of Player 2';
            else
                app.Player = 1;
                app.Button_2.Text = 'X';
                app.mat(1,2) = 2;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Player 1 Turn';
            end
            app.Button_2.Enable = 'off';
            tictactoe(app,app.mat);
            
        end

        % Button pushed function: Button_3
        function Button_3Pushed(app, event)
            if app.Player == 1
                app.Player = 2;
                app.Button_3.Text = 'O';
                app.mat(1,3) = 1;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Turn of Player 2';
            else
                app.Player = 1;
                app.Button_3.Text = 'X';
                app.mat(1,3) = 2;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Player 1 Turn';
            end
            app.Button_3.Enable = 'off';
            tictactoe(app,app.mat);
            
        end

        % Button pushed function: Button_4
        function Button_4Pushed(app, event)
            if app.Player == 1
                app.Player = 2;
                app.Button_4.Text = 'O';
                app.mat(2,1) = 1;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Turn of Player 2';
            else
                app.Player = 1;
                app.Button_4.Text = 'X';
                app.mat(2,1) = 2;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Player 1 Turn';
            end
            app.Button_4.Enable = 'off';
            tictactoe(app,app.mat);
            
        end

        % Button pushed function: Button_5
        function Button_5Pushed(app, event)
            if app.Player == 1
                app.Player = 2;
                app.Button_5.Text = 'O';
                app.mat(2,2) = 1;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Turn of Player 2';
            else
                app.Player = 1;
                app.Button_5.Text = 'X';
                app.mat(2,2) = 2;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Player 1 Turn';
            end
            app.Button_5.Enable = 'off';
            tictactoe(app,app.mat);
            
        end

        % Button pushed function: Button_6
        function Button_6Pushed(app, event)
            if app.Player == 1
                app.Player = 2;
                app.Button_6.Text = 'O';
                app.mat(2,3) = 1;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Turn of Player 2';
            else
                app.Player = 1;
                app.Button_6.Text = 'X';
                app.mat(2,3) = 2;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Player 1 Turn';
            end
            app.Button_6.Enable = 'off';
            tictactoe(app,app.mat);
            
        end

        % Button pushed function: Button_7
        function Button_7Pushed(app, event)
            if app.Player == 1
                app.Player = 2;
                app.Button_7.Text = 'O';
                app.mat(3,1) = 1;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Turn of Player 2';
            else
                app.Player = 1;
                app.Button_7.Text = 'X';
                app.mat(3,1) = 2;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Player 1 Turn';
            end
            app.Button_7.Enable = 'off';
            tictactoe(app,app.mat);
            
        end

        % Button pushed function: Button_8
        function Button_8Pushed(app, event)
            if app.Player == 1
                app.Player = 2;
                app.Button_8.Text = 'O';
                app.mat(3,2) = 1;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Turn of Player 2';
            else
                app.Player = 1;
                app.Button_8.Text = 'X';
                app.mat(3,2) = 2;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Player 1 Turn';
            end
            app.Button_8.Enable = 'off';
            tictactoe(app,app.mat);
            
        end

        % Button pushed function: Button_9
        function Button_9Pushed(app, event)
            if app.Player == 1
                app.Player = 2;
                app.Button_9.Text = 'O';
                app.mat(3,3) = 1;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Turn of Player 2';
            else
                app.Player = 1;
                app.Button_9.Text = 'X';
                app.mat(3,3) = 2;
                app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Player 1 Turn';
            end
            app.Button_9.Enable = 'off';
            tictactoe(app,app.mat);
            
        end
    end

    % App initialization and construction
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)

            % Create UIFigure
            app.UIFigure = uifigure;
            app.UIFigure.Position = [100 100 640 480];
            app.UIFigure.Color = [0.00,0.00,0.00];
            app.UIFigure.Name = 'UI Figure';

            % Create Button_1
            app.Button_1 = uibutton(app.UIFigure, 'push');
            app.Button_1.ButtonPushedFcn = createCallbackFcn(app, @Button_1Pushed, true);
            app.Button_1.BackgroundColor = [1.00,1.00,1.00];
            app.Button_1.Position = [98 371 115 62];
            app.Button_1.Text = '-';

            % Create WelcometoTicTacToefromMATLABHelperLabel
            app.WelcometoTicTacToefromMATLABHelperLabel = uilabel(app.UIFigure);
            app.WelcometoTicTacToefromMATLABHelperLabel.Position = [173 431 296 22];
            app.WelcometoTicTacToefromMATLABHelperLabel.Text = 'Welcome to Tic Tac Toe from MATLAB Helper.';

            % Create Button_2
            app.Button_2 = uibutton(app.UIFigure, 'push');
            app.Button_2.ButtonPushedFcn = createCallbackFcn(app, @Button_2Pushed, true);
            app.Button_2.BackgroundColor = [1.00,1.00,1.00];
            app.Button_2.Position = [251 371 121 62];
            app.Button_2.Text = '-';

            % Create Button_3
            app.Button_3 = uibutton(app.UIFigure, 'push');
            app.Button_3.ButtonPushedFcn = createCallbackFcn(app, @Button_3Pushed, true);
            app.Button_3.BackgroundColor = [1.00,1.00,1.00];
            app.Button_3.Position = [399 371 120 62];
            app.Button_3.Text = '-';

            % Create Button_4
            app.Button_4 = uibutton(app.UIFigure, 'push');
            app.Button_4.ButtonPushedFcn = createCallbackFcn(app, @Button_4Pushed, true);
            app.Button_4.BackgroundColor = [1.00,1.00,1.00];
            app.Button_4.Position = [98 288 115 64];
            app.Button_4.Text = '-';

            % Create Button_5
            app.Button_5 = uibutton(app.UIFigure, 'push');
            app.Button_5.ButtonPushedFcn = createCallbackFcn(app, @Button_5Pushed, true);
            app.Button_5.BackgroundColor = [1.00,1.00,1.00];
            app.Button_5.Position = [251 288 119 65];
            app.Button_5.Text = '-';

            % Create Button_6
            app.Button_6 = uibutton(app.UIFigure, 'push');
            app.Button_6.ButtonPushedFcn = createCallbackFcn(app, @Button_6Pushed, true);
            app.Button_6.BackgroundColor = [1.00,1.00,1.00];
            app.Button_6.Position = [98 206 115 66];
            app.Button_6.Text = '-';

            % Create Button_7
            app.Button_7 = uibutton(app.UIFigure, 'push');
            app.Button_7.ButtonPushedFcn = createCallbackFcn(app, @Button_7Pushed, true);
            app.Button_7.BackgroundColor = [1.00,1.00,1.00];
            app.Button_7.Position = [251 371 121 62];
            app.Button_7.Text = '-';

            % Create Button_8
            app.Button_8 = uibutton(app.UIFigure, 'push');
            app.Button_8.ButtonPushedFcn = createCallbackFcn(app, @Button_8Pushed, true);
            app.Button_8.BackgroundColor = [1.00,1.00,1.00];
            app.Button_8.Position = [399 205 120 67];
            app.Button_8.Text = '-';

            % Create Button_9
            app.Button_9 = uibutton(app.UIFigure, 'push');
            app.Button_9.ButtonPushedFcn = createCallbackFcn(app, @Button_9Pushed, true);
            app.Button_9.BackgroundColor = [1.00,1.00,1.00];
            app.Button_9.Position = [250 206 120 67];
            app.Button_9.Text = '-';

            % Create NewGameButton
            app.NewGameButton = uibutton(app.UIFigure, 'push');
            app.NewGameButton.ButtonPushedFcn = createCallbackFcn(app, @NewGameButtonPushed, true);
            app.NewGameButton.Position = [271 86 100 22];
            app.NewGameButton.Text = 'New Game';
        end
    end

    methods (Access = public)

        % Construct app
        function app = TTT

            % Create and configure components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            % Execute the startup function
            runStartupFcn(app, @startupFcn)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end
