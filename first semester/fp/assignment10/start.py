from UI.ui import UI
with open('player_stats.txt', 'w') as f:
    f.write('0')
    f.close()
with open('comp_stats.txt', 'w') as f:
    f.write('0')
    f.close()
ui = UI()
ui.start_game()
